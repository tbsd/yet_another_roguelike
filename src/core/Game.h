#ifndef TBSD_ROGUELIKE_GAME_H
#define TBSD_ROGUELIKE_GAME_H
#include "Server.h"
#include "IO.h"
#include "ServerCommand.h"
#include "entityx/entityx.h"

namespace tbsd {
  /// Contains general information about game and handles reaction to user actions
  class Game {
    Server& server;
    entityx::EventManager events;
    entityx::EntityManager entities;
    entityx::SystemManager systems;

  public:
    explicit Game(Server& server) : server(server), entities(events), systems(entities, events) {}

    /// Starts main game loop
    void run();

private:
  /// Processes command from server command line
  void processCommand(ServerCommand command);
  };
}


#endif //TBSD_ROGUELIKE_GAME_H
