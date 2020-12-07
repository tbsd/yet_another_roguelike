#ifndef TBSD_ROGUELIKE_MOVEEVENT_H
#define TBSD_ROGUELIKE_MOVEEVENT_H
#include "../component/Position.h"
#include "entityx/Entity.h"

namespace tbsd {
  struct MoveEvent {
    entityx::Entity target;
    Position pos;

    MoveEvent(entityx::Entity& target, Position pos) : target(target), pos(pos) {}
  };
}


#endif //TBSD_ROGUELIKE_MOVEEVENT_H
