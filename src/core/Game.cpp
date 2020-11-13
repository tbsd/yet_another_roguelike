#include "Game.h"
#include "Log.h"
#include <mutex>
#include <future>
#include <chrono>
#include "UserAction.h"

namespace tbsd {
  void Game::run() {
    std::string consoleInput;
    std::future<std::string> console = std::async([&]{return io.getFromConsole();});
    // Main game loop
    while (true) {
      // Process data from console
      if (console.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
        consoleInput = console.get();
        ServerCommand command = io.parseCommand(consoleInput);
        Log::send(std::to_string(command));
        if (command == Shutdown)
          return;
        else
          processCommand(command);
        console = std::async([&]{return io.getFromConsole();});
      }
      // Process data from server
      std::mutex m;
      m.lock();
      if (server.hasUserActions()) {
        auto action = server.getUserAction();
        m.unlock();
        Log::send(action->data, Log::Received);
        server.send(*action); // echo
      } else
        m.unlock();
    }
  }

  void Game::processCommand(ServerCommand command) {

  }

}
