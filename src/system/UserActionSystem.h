#ifndef USERACTIONSYSTEM_H
#define USERACTIONSYSTEM_H
#include <string>
#include "entityx/entityx.h"
#include "entityx/System.h"
#include "entityx/Entity.h"
#include "../event/UserActionEvent.h"
#include "../component/Position.h"
#include "nlohmann/json.hpp"

namespace RoguesParty {
  /** Handles user actions */
  class UserActionSystem : public entityx::System<UserActionSystem>, 
  public entityx::Receiver<UserActionSystem> {
    public:
      void configure(entityx::EventManager &em) {
        em.subscribe<UserActionEvent>(*this);
      }

      void update(entityx::EntityManager &entities, entityx::EventManager &events,
          entityx::TimeDelta dt) {}

      void receive(const UserActionEvent &userActionEvent) {
        /// TODO: add multiple actions processing
        // for userActionEvent.actions["type"]
        moveObject(userActionEvent);
        // switch (userActionEvent.actions[""type]) {
          // case UserAction::MOVE:
            // moveObject(userActionEvent);
            // break;
          // case UserAction::ATTACK:
            // break;
        // }
      }

    private:
      void moveObject(const UserActionEvent &userActionEvent) {
        auto &params = userActionEvent.actions;
        auto entity = userActionEvent.userEntity;
        auto position = entity.component<Position>();
        /// guard against wrong type cast
        try {
          position->x += static_cast<Coordinate>(params["move"]["x"]);
          position->y += static_cast<Coordinate>(params["move"]["y"]);
          position->z += static_cast<Coordinate>(params["move"]["z"]);
        } catch (const nlohmann::json::type_error &e) {
          std::cerr <<  e.what() << std::endl;
        }
        std::cout << "(" << position->x  << ", " << position->y << ", " << 
          position->z << ")" << std::endl;
      }
  };
}

#endif
