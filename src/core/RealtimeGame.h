#ifndef TBSD_ROGUELIKE_REALTIMEGAME_H
#define TBSD_ROGUELIKE_REALTIMEGAME_H
#include "Game.h"
#include <chrono>

namespace tbsd {
  class RealtimeGame : public Game {
    std::chrono::milliseconds delay;
    Unit apPerTurn;

  public:
    explicit RealtimeGame(Server& server, std::chrono::milliseconds delay, Unit apPerTurn)
    : Game(server), delay(delay), apPerTurn(apPerTurn) {}

    void run() override;
  };
}


#endif //TBSD_ROGUELIKE_REALTIMEGAME_H
