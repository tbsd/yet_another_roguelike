//
// Created by subject on 11/14/20.
//

#include "WorldMap.h"

namespace tbsd {
  std::string WorldMap::BaseMap::Chunk::toString() const {
    std::string result;
    result.reserve(chunkSize * chunkSize * chunkSize + 3 * chunkSize);
    for (size_t z = 0; z < chunkSize; ++z) {
      result += std::to_string(z) + "\n";
      for (size_t y = 0; y < chunkSize; ++y) {
        for (size_t x = 0; x < chunkSize; ++x) {
          result.push_back(static_cast<char>(chunk[x][y][z].type));
        }
        result.push_back('\n');
      }
    }
    return result;
  }

}
