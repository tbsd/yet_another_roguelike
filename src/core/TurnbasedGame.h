#ifndef TBSD_ROGUELIKE_TURNBASEDGAME_H
#define TBSD_ROGUELIKE_TURNBASEDGAME_H
#include "Game.h"

namespace tbsd {
  class TurnbasedGame : public Game {
  public:
    using Game::Game;

    void run() override;
  };
}


#endif //TBSD_ROGUELIKE_TURNBASEDGAME_H
