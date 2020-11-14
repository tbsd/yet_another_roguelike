//
// Created by subject on 11/15/20.
//

#ifndef TBSD_ROGUELIKE_POSITION_H
#define TBSD_ROGUELIKE_POSITION_H

/// Represents coordinate type
using Coordinate = long;

/// Contains 3d coordinates
struct Position {
  Coordinate x;
  Coordinate y;
  Coordinate z;

  Position(Coordinate x, Coordinate y, Coordinate z): x(x), y(y), z(z) {}
};


#endif //TBSD_ROGUELIKE_POSITION_H
