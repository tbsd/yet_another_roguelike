#ifndef TBSD_ROGUELIKE_DIRECTION_H
#define TBSD_ROGUELIKE_DIRECTION_H

namespace tbsd {
  /// Represents 8-connectivity neighbourhood directions
  enum class Direction {
    UpLeft, Up, UpRight,
    Left, Center, Right,
    DownLeft, Down, DownRight,
    _last
  };
}

#endif //TBSD_ROGUELIKE_DIRECTION_H
