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
        Log::send("Received command: " + consoleInput);
        console = std::async([&]{return io.getFromConsole();});
      }
      // Process data from server
      std::mutex m;
      m.lock();
      if (server.hasUserActions()) {
        auto action = server.getUserAction();
        m.unlock();
        Log::send(action->second, Log::Received);
        server.send(action->second, action->first); // echo
      } else
        m.unlock();
    }
  }

}
