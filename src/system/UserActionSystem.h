#ifndef USERACTIONSYSTEM_H
#define USERACTIONSYSTEM_H
#include <string>
#include "entityx/entityx.h"
#include "entityx/System.h"
#include "entityx/Entity.h"
#include "../event/UserActionEvent.h"
#include "../component/Position.h"
#include "../component/User.h"
#include "nlohmann/json.hpp"
#include "../event/MapChangeEvent.h"

namespace RoguesParty {
  /** Handles user actions */
  class UserActionSystem : public entityx::System<UserActionSystem>, 
  public entityx::Receiver<UserActionSystem> {
    private:
      entityx::EventManager &em;

    public:
      UserActionSystem(entityx::EventManager &em) : em(em) {}

      void configure(entityx::EventManager &em) {
        em.subscribe<UserActionEvent>(*this);
      }

      void update(entityx::EntityManager &entities, entityx::EventManager &events,
          entityx::TimeDelta dt) {}

      void receive(const UserActionEvent &userActionEvent) {
        auto target = userActionEvent.userEntity;
        auto actions = userActionEvent.actions;
        if (actions.contains("move"))
          moveObject(target, actions["move"]);
      }

    private:
      void moveObject(entityx::Entity target, nlohmann::json params) {
        auto pos = target.component<Position>();
        /// guard against wrong type cast
        try {
          nlohmann::json mapChange;
          mapChange["type"] = "move";
          mapChange["from"] = {pos->x, pos->y, pos->z};
          pos->x += static_cast<Coordinate>(params["x"]);
          pos->y += static_cast<Coordinate>(params["y"]);
          pos->z += static_cast<Coordinate>(params["z"]);
          mapChange["to"] = {pos->x, pos->y, pos->z};
          em.emit<MapChangeEvent>(target, mapChange);
        } catch (const nlohmann::json::type_error &e) {
          std::cerr <<  e.what() << std::endl;
        }
        std::cout << "(" << pos->x  << ", " << pos->y << ", " << 
          pos->z << ")" << std::endl;
      }
  };
}

#endif
