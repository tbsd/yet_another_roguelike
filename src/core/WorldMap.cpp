//
// Created by subject on 11/14/20.
//

#include "WorldMap.h"

namespace tbsd {
  std::string WorldMap::BaseMap::Chunk::toString() const {
    std::string result;
    result.reserve(chunkXSize * chunkYSize  + chunkYSize);
    for (size_t y = 0; y < chunkYSize; ++y) {
      for (size_t x = 0; x < chunkXSize; ++x) {
        result.push_back(static_cast<char>(at(x, y)->type));
      }
      result.push_back('\n');
    }
    return result;
  }

  unsigned long long WorldMap::BaseMap::Chunk::nextId = 0;

  WorldMap::Tile *WorldMap::BaseMap::at(Position pos) {
    return map[pos.x / Chunk::chunkXSize][pos.y / Chunk::chunkYSize]
        .at(pos.x % Chunk::chunkXSize, pos.y % Chunk::chunkYSize);
  }

  WorldMap::Tile *WorldMap::at(Position pos) {
    return mainMap.at(pos);
  }
}
