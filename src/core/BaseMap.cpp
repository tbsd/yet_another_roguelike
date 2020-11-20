#include "BaseMap.h"

namespace tbsd {
  Tile* BaseMap::at(Position pos) {
    Chunk& chunk = map[pos.x / Chunk::chunkXSize][pos.y / Chunk::chunkYSize];
    chunk.load();
    return chunk.at(pos.x % Chunk::chunkXSize, pos.y % Chunk::chunkYSize);
  }
}