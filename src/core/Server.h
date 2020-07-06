#ifndef SERVER_H
#define SERVER_H
#include "server/asio/service.h"
#include "server/ws/ws_server.h"
#include <iostream>
#include "Game.h"
#include "../event/UserActionEvent.h"
#include "nlohmann/json.hpp"

namespace RoguesParty {
  /** Contains current game and handles user connections to it in asincronious 
   * way.*/
  class Server {
    private:
      class AsioService : public CppServer::Asio::Service {
        protected:
          void onError(int error, const std::string& category, const std::string& message) override {
            std::cout << "Error: " << error << " '" << category << "': " << message
              << std::endl;
          }
      };

      class WebSocketSession : public CppServer::WS::WSSession {
        public:
          using CppServer::WS::WSSession::WSSession;

          Game *game;

        protected:
          void onWSConnected(const CppServer::HTTP::HTTPRequest& request) override {
            std::cout << "Connected: " << id() << std::endl;
            game->startUserSession(id().string());
          }

          void onWSDisconnected() override {
            std::cout << "Disconnected: " << id() << std::endl;
            game->endUserSession(id().string());
          }

          void onWSReceived(const void* buffer, size_t size) override {
            std::string rawData((const char*)buffer, size);
            // If the buffer starts with '!' the disconnect the current session
            if (rawData == "!")
              Close(1000);
            try {
              auto data = nlohmann::json::parse(rawData);
              SendTextAsync("Echoing: " + rawData);
              game->processInput(id().string(), data);
            } catch (const nlohmann::json::parse_error &e) {
              /// TODO: replace with Log output system with timestamp, 
              /// decoration and stuff
              std::cerr << e.what() << " | Session id: " << id() << " | Recieved data: " << 
                rawData << std::endl;
            }
          }

          void onError(int error, const std::string& category, const std::string& message) override {
            std::cout << "Error: " << error << " '" << category << "': " << message
              << std::endl;
          }
      };

      class WebSocketServer : public CppServer::WS::WSServer {
        public:
          using CppServer::WS::WSServer::WSServer;

          Game *game;

        protected:
          std::shared_ptr<CppServer::Asio::TCPSession> CreateSession(
              const std::shared_ptr<CppServer::Asio::TCPServer>& server) override {
            auto session = std::make_shared<WebSocketSession>(
                std::dynamic_pointer_cast<CppServer::WS::WSServer>(server));
            session->game = game;
            return session;
          }

          void onError(int error, const std::string& category, 
              const std::string& message) override {
            std::cout << "Error: " << error << " '" << category << "': " << message 
              << std::endl;
          }
      };


    private:
      Game &game;
      std::shared_ptr<AsioService> service;
      std::shared_ptr<WebSocketServer> server;

    public:
      Server(Game &game, int port = 4096) : game(game) {
        service = std::make_shared<AsioService>();
        server = std::make_shared<WebSocketServer>(service, port);
        server->game = &game;
        std::cout << "Port: " << port << std::endl;
        std::cout << "Full link: " << "http://localhost:" << port << std::endl;
      };

      ~Server();

      /** Starts server */
      void run();

  };
}

#endif
