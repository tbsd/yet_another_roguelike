#ifndef TBSD_ROGUELIKE_WORLDMAP_H
#define TBSD_ROGUELIKE_WORLDMAP_H
#include <list>


namespace tbsd {
  class WorldMap {
    using Tile = char;
    class BaseMap {
      class Chunk {
      public:
        static constexpr int chunkSize = 10;
      private:
        Tile chunk[chunkSize][chunkSize][chunkSize];

      public:
        Tile& get(size_t x, size_t y, size_t z) {
          return &chunk[x][y][z];
        }
      };

      // type of map should allow fast insertion and remove of the first and
      // the last element for fast deserialization on demand
      std::list<std::list<Chunk>> map;

    public:
      /// Parameters must be 1 or greater
      BaseMap(size_t xChunksCount, size_t yChunksCount) : map(xChunksCount, std::list<Chunk>(yChunksCount)) {};

      BaseMap() : BaseMap(1, 1) {};


    };

    BaseMap mainMap;
  };
}


#endif //TBSD_ROGUELIKE_WORLDMAP_H
