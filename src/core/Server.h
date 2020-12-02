#ifndef SERVER_H
#define SERVER_H
#include "server/asio/service.h"
#include "server/ws/ws_server.h"
#include "Log.h"
#include <queue>
#include <utility>
#include <mutex>
#include <nlohmann/json.hpp>
#include "RawData.h"
#include "Action.h"

namespace tbsd {
  /** Handles user connections to it in asynchronous way.*/
  class Server {
  private:
    class AsioService : public CppServer::Asio::Service {
    protected:
      void onError(int error, const std::string& category, const std::string& message) override {
        Log::send(std::to_string(error) + ": " + category + ": " + message, Log::Type::Error);
      }
    };

    class WebSocketSession : public CppServer::WS::WSSession {
    public:
      using CppServer::WS::WSSession::WSSession;
      std::queue<RawData>& userActions;
      WebSocketSession(const std::shared_ptr<CppServer::WS::WSServer>& server,
                       std::queue<RawData>& userActions)
                       : CppServer::WS::WSSession(server), userActions(userActions) {};

    protected:
      void onWSConnected(const CppServer::HTTP::HTTPRequest& request) override {
        Log::send("Connected: " + id().string());
        nlohmann::json connectionData;
        connectionData["action"] = Action::Type::Connected;
        static std::mutex m;
        m.lock();
        userActions.emplace(this, connectionData.dump()); // TODO: replace pointers with IDs?
        m.unlock();
      }

      void onWSDisconnected() override {
        Log::send("Disconnected: " + id().string());
        nlohmann::json connectionData;
        connectionData["action"] = Action::Type::Disconnected;
        static std::mutex m;
        m.lock();
        userActions.emplace(this, connectionData.dump());
        m.unlock();
      }

      void onWSReceived(const void* buffer, size_t size) override {
        std::string data((const char*) buffer, size);
        static std::mutex m;
        m.lock();
        userActions.emplace(this, data);
        m.unlock();
      }



      void onError(int error, const std::string& category, const std::string& message) override {
        Log::send(std::to_string(error) + ": " + category + ": " + message, Log::Type::Error);
      }
    };

    class WebSocketServer : public CppServer::WS::WSServer {
    public:
      using CppServer::WS::WSServer::WSServer;

    protected:
      std::shared_ptr<CppServer::Asio::TCPSession> CreateSession(
          const std::shared_ptr<CppServer::Asio::TCPServer>& server) override {
        auto session = std::make_shared<WebSocketSession>(
            std::dynamic_pointer_cast<CppServer::WS::WSServer>(server), userActions);
        return session;
      }

      void onError(int error, const std::string& category, const std::string& message) override {
        Log::send(std::to_string(error) + ": " + category + ": " + message, Log::Type::Error);
      }

    private:
      friend Server;
      std::queue<RawData> userActions;
    };


  private:
    std::shared_ptr<AsioService> service;
    std::shared_ptr<WebSocketServer> server;

  public:
    Server(int port) {
      service = std::make_shared<AsioService>();
      server = std::make_shared<WebSocketServer>(service, port);
      Log::send("Port: " + std::to_string(port));
      Log::send("Full link: http://localhost:" + std::to_string(port));
    };

    ~Server();

    /** Starts server */
    void run();

    bool hasUserActions() {
      return !server->userActions.empty();
    }

    RawData* getUserAction() {
      if (server->userActions.empty())
        return nullptr;
      auto action = &server->userActions.front();
      server->userActions.pop();
      return action;
    }

    void send(RawData &message) {
      if (message.session->IsConnected()) {
        message.session->Send(message.data);
      } else {
        Log::send("Attempt to sending to disconnected client. Id: " + message.session->id().string(), Log::Warning);
      }
    }

  };
}

#endif
