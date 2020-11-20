#ifndef TBSD_ROGUELIKE_WORLDMAP_H
#define TBSD_ROGUELIKE_WORLDMAP_H
#include <list>
#include <vector>
#include <string>
#include <array>
#include "../component/Position.h"
#include "Tile.h"
#include "BaseMap.h"


namespace tbsd {
  class WorldMap {
    BaseMap mainMap; // main world map

  public:
    [[nodiscard]]
    Tile* at(Position pos);
  };
}


#endif //TBSD_ROGUELIKE_WORLDMAP_H
