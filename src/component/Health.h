#ifndef TBSD_ROGUELIKE_HEALTH_H
#define TBSD_ROGUELIKE_HEALTH_H
#include "../core/Unit.h"

namespace tbsd {
  /// Stores health data
  struct Health {
    Unit max;
    Unit hp;

    Health(Unit max, Unit hp) : max(max), hp(hp) {}
    Health(Unit max) : max(max), hp(max) {}
  };
}

#endif //TBSD_ROGUELIKE_HEALTH_H
