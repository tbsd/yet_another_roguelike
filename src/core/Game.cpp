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
#include <algorithm>

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
    return delta(id);
  }

  nlohmann::json Game::fullData(std::string id) {
    return nlohmann::json();
  }

  nlohmann::json Game::initData(std::string id) {
    return delta(id);
  }

  entityx::Entity Game::getUser(std::string_view id) {
    entityx::ComponentHandle<User> userComp;
    for (auto user : this->entities.entities_with_components(userComp)) 
      if (userComp->id == id)
        return user;
    // TODO: replace with something meaningfull
    return entityx::Entity();
  }

  /** Returns difference between current map state and changes made for 
   * given user. Updates user caheMap */
  nlohmann::json Game::delta(std::string id) {
    auto user = getUser(id).component<User>();
    std::list<nlohmann::json> changes;
    auto xSize = std::min(world.map.map.size(), user->mapCache.size());
    auto ySize = std::min(world.map.map[0].size(), user->mapCache[0].size());
    std::cout << xSize << " " << ySize << std::endl;
    for (size_t i = 0; i < xSize; ++i) {
      for (size_t j = 0; j < ySize; ++j) {
        if (user->mapCache[i][j] != world.map.map[i][j]) {
          changes.emplace_back(nlohmann::json {
              {"type", world.map.map[i][j].type},
              {"x", i},
              {"y", j},
              {"z", 0}});
          user->mapCache[i][j] = world.map.map[i][j];
        }
      }
    }
    return {{"field", changes}};
  }
}
