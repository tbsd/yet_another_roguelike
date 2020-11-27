#ifndef TBSD_ROGUELIKE_STATUSEFFECTS_H
#define TBSD_ROGUELIKE_STATUSEFFECTS_H
#include "entityx/Entity.h"
#include <list>

namespace tbsd {
  /// Stores information about positive and negative status effects
  struct StatusEffects {
    std::list<entityx::Entity> effects;

    StatusEffects() = default;
  };
}

#endif //TBSD_ROGUELIKE_STATUSEFFECTS_H
