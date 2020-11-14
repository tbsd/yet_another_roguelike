//
// Created by subject on 11/14/20.
//

#include "WorldMap.h"

namespace tbsd {
  std::string WorldMap::BaseMap::Chunk::toString() const {
    std::string result;
    result.reserve(chunkXSize * chunkYSize * chunkZSize + chunkYSize + 2*chunkZSize);
    for (size_t z = 0; z < chunkZSize; ++z) {
      result += std::to_string(z) + "\n";
      for (size_t y = 0; y < chunkYSize; ++y) {
        for (size_t x = 0; x < chunkXSize; ++x) {
          result.push_back(static_cast<char>(at(x, y, z)->type));
        }
        result.push_back('\n');
      }
    }
    return result;
  }

  WorldMap::Tile *WorldMap::BaseMap::at(Position pos) {
    return map[pos.x / Chunk::chunkXSize][pos.y / Chunk::chunkYSize]
    .at(pos.x % Chunk::chunkXSize, pos.y % Chunk::chunkYSize, pos.y);
  }

  WorldMap::Tile *WorldMap::at(Position pos) {
    return mainMap.at(pos);
  }
}
