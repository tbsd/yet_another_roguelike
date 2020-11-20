//
// Created by subject on 11/14/20.
//

#include "WorldMap.h"

namespace tbsd {
  Tile* WorldMap::at(Position pos) {
    return mainMap.at(pos);
  }
}
