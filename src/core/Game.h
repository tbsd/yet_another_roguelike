#ifndef GAME_H
#define GAME_H
#include "entityx/entityx.h"
#include "../component/Position.h"
#include "World.h"
#include "nlohmann/json.hpp"

namespace RoguesParty {
  /** Contains and changes game state */
  class Game : public entityx::EntityX {
    private:
      World world;

    public:
      Game();

      /** Process events planned for the next turn */
      void update(entityx::TimeDelta dt);

      /** Process input commands */
      void processInput(std::string_view id, nlohmann::json actions);

      /** Adds new player session to the game */
      void startUserSession(std::string id);

      /** Ends player session */
      void endUserSession(std::string id);
  };
}

#endif
