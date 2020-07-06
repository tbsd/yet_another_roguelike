#ifndef POSITION_H
#define POSITION_H
#include "../core/Coordinate.h"

namespace RoguesParty {
  /** Contains position of object on map */
  struct Position {
    Coordinate x, y, z;

    Position(Coordinate x, Coordinate y, Coordinate z) : x(x), y(y), z(z) {}
  };
}

#endif
