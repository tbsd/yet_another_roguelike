#include "Game.h"
#include "Log.h"
#include <mutex>
#include <future>
#include <chrono>
#include "UserAction.h"
#include "../component/Health.h"

namespace tbsd {
  void Game::processAction(const Action& action) {
    switch (action.getType()) {
      case Action::Type::Connected:
        users.emplace_back(std::any_cast<CppServer::WS::WSSession*>(action.data.back()));
        {
          entityx::Entity playableChar = entities.create();
          playableChar.assign<Position>(0, 0, 0);
          playableChar.assign<Health>(100);
          users.back().owned.push_back(playableChar);
        }
        break;
      case Action::Type::Disconnected:
        auto session = std::any_cast<CppServer::WS::WSSession*>(action.data.back());
        users.erase(
            std::remove_if(users.begin(), users.end(), [&](User& u) {return u.session == session;}),
            users.end());
        break;
    }
  }

  void Game::processCommand(ServerCommand command) {
    switch (command) {
      case Empty:
        break;
      case Invalid:
      default:
        Log::send("Invalid command", Log::Warning);
    }
  }

  void Game::mainLoop(std::function<void(void)> newActionsHandler) {
    std::string consoleInput;
    std::future<std::string> console = std::async([&]{return IO::getFromConsole();});
    // Main game loop
    while (true) {
      // Process data from console
      if (console.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
        consoleInput = console.get();
        ServerCommand command = IO::parseCommand(consoleInput);
        if (command == Shutdown)
          return;
        else
          processCommand(command);
        console = std::async([&]{return IO::getFromConsole();});
      }
      // Process data from server
      static std::mutex m;
      m.lock();
      if (server.hasUserActions()) {
        auto action = server.getUserAction();
        try {
          Action newAction(action->data);
          // TODO: thing of a better way of adding pointers
          //  and not adding session where there no need for that
          newAction.data.emplace_back(action->session);
          actions.push(newAction);
        } catch (std::exception &ex) {
          Log::send(ex.what(), Log::Error);
        }
        m.unlock();
        Log::send(action->data, Log::Received);
        server.send(*action); // echo
      } else
        m.unlock();
//      processActions();
      newActionsHandler();
    }
  }

  void Game::decreaseTime(Unit amount) {
    // TODO: replace with a better solution. Create priority queue with random access?
    std::priority_queue<Action, std::vector<Action>,  Action::Greater> decreased;
    while (!actions.empty()) {
      auto action = actions.top();
      actions.pop();
      action.time -= amount;
      decreased.push(action);
    }
    actions = decreased;
  }

}
