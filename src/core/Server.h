#ifndef SERVER_H
#define SERVER_H
#include "server/asio/service.h"
#include "server/ws/ws_server.h"
#include <iostream>

namespace tbsd {
  /** Handles user connections to it in asynchronous way.*/
  class Server {
  private:
    class AsioService : public CppServer::Asio::Service {
    protected:
      void onError(int error, const std::string& category, const std::string& message) override {
        std::cerr << "Error: " << error << " '" << category << "': " << message << std::endl;
      }
    };

    class WebSocketSession : public CppServer::WS::WSSession {
    public:
      using CppServer::WS::WSSession::WSSession;

    protected:
      void onWSConnected(const CppServer::HTTP::HTTPRequest& request) override {
        std::cout << "Connected: " << id() << std::endl;
      }

      void onWSDisconnected() override {
        std::cout << "Disconnected: " << id() << std::endl;
      }

      void onWSReceived(const void* buffer, size_t size) override {
      }

      void onError(int error, const std::string& category, const std::string& message) override {
        std::cerr << "Error: " << error << " '" << category << "': " << message << std::endl;
      }
    };

    class WebSocketServer : public CppServer::WS::WSServer {
    public:
      using CppServer::WS::WSServer::WSServer;

    protected:
      std::shared_ptr<CppServer::Asio::TCPSession> CreateSession(
          const std::shared_ptr<CppServer::Asio::TCPServer>& server) override {
        auto session = std::make_shared<WebSocketSession>(
            std::dynamic_pointer_cast<CppServer::WS::WSServer>(server));
        return session;
      }

      void onError(int error, const std::string& category, const std::string& message) override {
        std::cerr << "Error: " << error << " '" << category << "': " << message << std::endl;
      }
    };


  private:
    std::shared_ptr<AsioService> service;
    std::shared_ptr<WebSocketServer> server;

  public:
    Server(int port) {
      service = std::make_shared<AsioService>();
      server = std::make_shared<WebSocketServer>(service, port);
      std::cout << "Port: " << port << std::endl;
      std::cout << "Full link: " << "http://localhost:" << port << std::endl;
    };

    ~Server();

    /** Starts server */
    void run();

  };
}

#endif
