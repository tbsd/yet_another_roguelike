#ifndef MAPCHANGEEVENT_H
#define MAPCHANGEEVENT_H
#include "../core/Map.h"
#include "nlohmann/json.hpp"
#include "entityx/Entity.h"
#include <memory>

namespace RoguesParty {
  struct MapChangeEvent {
    std::shared_ptr<entityx::Entity> target; 
    nlohmann::json action;

    MapChangeEvent(entityx::Entity target, nlohmann::json action) : 
      target(target), action(action) {};
  };
}

#endif
