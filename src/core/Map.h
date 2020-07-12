#ifndef MAP_H
#define MAP_H
#include "Chunk.h"
#include <vector>
#include <list>
#include "../core/TileType.h"
#include "nlohmann/json.hpp"
#include "../core/Coordinate.h"

namespace RoguesParty {
  /** Contains map data. Handles object positioning on map */
  class Map {
    friend class MapChangeSystem;
    friend class Game;
    private:
      std::vector<std::vector<TileType>> map;
      std::vector<std::vector<TileType>> changedMap;
      std::vector<std::vector<TileType>> previousMap;

    public:
      Map() {
        int mapXSize, mapYSize;
        mapXSize = mapYSize = 50;
        map.resize(mapYSize, std::vector<TileType>(mapXSize, TileType::GROUND));
        changedMap.resize(mapYSize, std::vector<TileType>(mapXSize, TileType::GROUND));
        previousMap.resize(mapYSize, std::vector<TileType>(mapXSize, TileType::GROUND));
        map[0][0] = changedMap[0][0] = previousMap[0][0] = TileType::HUMAN;
      }

  };
}

#endif
