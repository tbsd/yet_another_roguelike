#include "Game.h"
#include "Log.h"
#include <mutex>

namespace tbsd {
  void Game::run() {
    while (true) {
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
