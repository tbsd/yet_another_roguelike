#ifndef TBSD_ROGUELIKE_GAME_H
#define TBSD_ROGUELIKE_GAME_H
#include "Server.h"

namespace tbsd {
  /// Contains general information about game and handles reaction to user actions
  class Game {
    Server& server;

  public:
    explicit Game(Server& server) : server(server){}

    /// Starts main game loop
    void run();
  };
}


#endif //TBSD_ROGUELIKE_GAME_H
