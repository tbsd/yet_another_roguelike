#include "Chunk.h"

namespace tbsd {
  unsigned long long Chunk::nextId = 0;

  std::string Chunk::toString() const {
    std::string result;
    result.reserve(chunkXSize * chunkYSize + chunkYSize);
    for (size_t y = 0; y < chunkYSize; ++y) {
      for (size_t x = 0; x < chunkXSize; ++x) {
        result.push_back(static_cast<char>(at(x, y)->type));
      }
      result.push_back('\n');
    }
    return result;
  }
}