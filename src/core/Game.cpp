#include "Game.h"
#include "../component/User.h"
#include "../component/Position.h"
#include "entityx/Entity.h"
#include "../system/UserActionSystem.h"
#include "nlohmann/json.hpp"
#include <string>

namespace RoguesParty {

  Game::Game() {
    systems.add<UserActionSystem>();
    systems.configure();
  }

  void Game::update(entityx::TimeDelta dt) {
    /// System updates go here
  }

  void Game::processInput(std::string_view id, nlohmann::json actions) {
    entityx::ComponentHandle<User> userComp;
    for (auto user : this->entities.entities_with_components(userComp)) {
      if (userComp->id == id)
        events.emit<UserActionEvent>(user, actions);
    }
  }

  void Game::startUserSession(std::string id) {
    entityx::Entity defaultUser = this->entities.create();
    defaultUser.assign<User>(id);
    /// TODO: change mock to loading actual user data
    defaultUser.assign<Position>(0, 0, 0);

  };

  void Game::endUserSession(std::string id) {
    /// TODO: add user data saving
  };
}
