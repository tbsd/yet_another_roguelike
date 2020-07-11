#include "Game.h"
#include "../component/User.h"
#include "../component/Position.h"
#include "entityx/Entity.h"
#include "../system/UserActionSystem.h"
#include "../system/MapChangeSystem.h"
#include "nlohmann/json.hpp"
#include "TileType.h"
#include <string>
#include <memory>

namespace RoguesParty {

  Game::Game() {
    systems.add<UserActionSystem>(events);
    mapChangeSystem = systems.add<MapChangeSystem>(world.map);
    systems.configure();
  }

  void Game::update(entityx::TimeDelta dt) {
    /// System updates go here
  }

  void Game::processInput(std::string_view id, nlohmann::json actions) {
    auto user = getUser(id);
    events.emit<UserActionEvent>(user, actions);
  }

  void Game::startUserSession(std::string id) {
    entityx::Entity defaultUser = this->entities.create();
    defaultUser.assign<User>(id);
    /// TODO: change mock to loading actual user data
    defaultUser.assign<Position>(0, 0, 0);
  }

  void Game::endUserSession(std::string id) {
    /// TODO: add user data saving
  }

  nlohmann::json Game::updatedData(std::string id) {
    mapChangeSystem->update();
    return mapChangeSystem->delta();
  }

  nlohmann::json Game::fullData(std::string id) {
    return nlohmann::json();
  }

  nlohmann::json Game::initData(std::string id) {
    return mapChangeSystem->delta();
  }

  entityx::Entity Game::getUser(std::string_view id) {
    entityx::ComponentHandle<User> userComp;
    for (auto user : this->entities.entities_with_components(userComp)) 
      if (userComp->id == id)
        return user;
    // TODO: replace with something meaningfull
    return entityx::Entity();
  }
}
