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

  Position(const Position& other): x(other.x), y(other.y), z(other.z) {}

  Position& operator+=(const Position& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  friend Position operator+(Position& lhs, Position& rhs) {
    return Position(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
  }

  Position operator-() const {
    return Position(-this.x, -this.y, -this.z);
  }

  Position& operator-=(const Position& lhs) {
    operator+=(-lhs);
    return *this;
  }

  friend Position operator-(Position& lhs, Position& rhs) {
    return Position(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
  }
};


#endif //TBSD_ROGUELIKE_POSITION_H
