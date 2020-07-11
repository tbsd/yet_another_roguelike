#ifndef MAPCHANGEEVENT_H
#define MAPCHANGEEVENT_H
#include "../core/Map.h"
#include "nlohmann/json.hpp"
#include "entityx/Entity.h"

namespace RoguesParty {
  struct MapChangeEvent {
    entityx::Entity target; 
    nlohmann::json action;

    MapChangeEvent(entityx::Entity target, nlohmann::json action) : 
      target(target), action(action) {};
  };
}

#endif
