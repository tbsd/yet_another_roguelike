#ifndef USERACTIONEVENT_H
#define USERACTIONEVENT_H
#include "entityx/Entity.h"
#include "nlohmann/json.hpp"

namespace RoguesParty {
  /** Contains data about actions user attampts to perform */
  struct UserActionEvent {
    entityx::Entity userEntity;
    nlohmann::json actions;

    UserActionEvent(entityx::Entity serEntity, nlohmann::json actions) : 
      userEntity(serEntity), actions(actions) {};
  };
}

#endif
