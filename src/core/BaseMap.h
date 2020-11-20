#ifndef TBSD_ROGUELIKE_BASEMAP_H
#define TBSD_ROGUELIKE_BASEMAP_H
#include <vector>
#include "Chunk.h"


namespace tbsd {
/// Contains map data
  class BaseMap {
    //TODO: make it add chunks for z dimension on demand
    //TODO: make it load/unload chunks on demand


    //TODO: add z levels
    std::vector <std::vector<Chunk>> map;

  public:
    /// Parameters must be 1 or greater
    BaseMap(size_t xChunksCount, size_t yChunksCount) : map(xChunksCount, std::vector<Chunk>(yChunksCount)) {};

    BaseMap() : BaseMap(1, 1) {};

    [[nodiscard]]
    Tile* at(Position pos);
  };
}


#endif //TBSD_ROGUELIKE_BASEMAP_H
