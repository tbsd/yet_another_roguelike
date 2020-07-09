#ifndef DAMAGEEVENT_H
#define DAMAGEEVENT_H
#include "entityx/Entity.h"

namespace RoguesParty {
  struct DamageEvent {
    entityx::Entity target;
    int damage;

    DamageEvent(entityx::Entity target, int damage) : target(target), damage(damage) {}
  };
}

#endif
