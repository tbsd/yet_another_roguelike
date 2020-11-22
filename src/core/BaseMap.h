#ifndef TBSD_ROGUELIKE_BASEMAP_H
#define TBSD_ROGUELIKE_BASEMAP_H
#include <array>
#include "Chunk.h"


namespace tbsd {
/// Contains map data
  class BaseMap {
    //TODO: make it add chunks for z dimension on demand
    //TODO: make it load/unload chunks on demand

    // Use std::array instead of std::vector so it can work with flatbuffers
    std::array<std::array<Chunk, 50>, 50> map;
    //TODO: think of scalable solution
    //TODO: add z levels

  public:
    [[nodiscard]]
    Tile* at(Position pos);
  };
}


#endif //TBSD_ROGUELIKE_BASEMAP_H
