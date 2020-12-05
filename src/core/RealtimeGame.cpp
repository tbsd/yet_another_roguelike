#include "RealtimeGame.h"

namespace tbsd {
  void RealtimeGame::run() {
    mainLoop([this] {
      static auto lastUpdate = std::chrono::system_clock::now();
      auto curTime = std::chrono::system_clock::now();
      if (lastUpdate + delay <= curTime) {
        lastUpdate = curTime;
        while (!actions.empty() && actions.top().time <= apPerTurn) {
          auto action = actions.top();
          processAction(action);
          actions.pop();
        }
        apTime += apPerTurn;
        decreaseTime(apPerTurn);
        Log::send("meh");
      }
    });
  }
}
