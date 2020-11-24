#ifndef TBSD_ROGUELIKE_HEALTH_H
#define TBSD_ROGUELIKE_HEALTH_H


namespace tbsd {
  /// Represents health points
  using HP = long;

  /// Stores health data
  struct Health {
    HP max;
    HP hp;

    Health(HP max, HP hp) : max(max), hp(hp) {}
    Health(HP max) : max(max), hp(max) {}
  };
}
#endif //TBSD_ROGUELIKE_HEALTH_H
