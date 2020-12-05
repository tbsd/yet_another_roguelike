#ifndef TBSD_ROGUELIKE_GAME_H
#define TBSD_ROGUELIKE_GAME_H
#include "Server.h"
#include "IO.h"
#include "ServerCommand.h"
#include "entityx/entityx.h"
#include "Action.h"
#include "User.h"

namespace tbsd {
  /// Contains general information about game and handles reaction to user actions
  class Game {
  protected:
    Server& server;
    entityx::EventManager events;
    entityx::EntityManager entities;
    entityx::SystemManager systems;
    std::priority_queue<Action, std::vector<Action>,  Action::Greater> actions;
    std::vector<User> users; // active users;
    Unit apTime = 0; // current game time in action points

  public:
    explicit Game(Server& server) : server(server), entities(events), systems(entities, events) {}

    /// Starts main game loop
    virtual void run() = 0;

    virtual ~Game() = default;

  protected:
    void mainLoop(std::function<void(void)> newActionsHandler);

    /// Processes command from server command line
    void processCommand(ServerCommand command);

    void processAction(const Action& action);
  };
}


#endif //TBSD_ROGUELIKE_GAME_H
