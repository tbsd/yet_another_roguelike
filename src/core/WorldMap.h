#ifndef TBSD_ROGUELIKE_WORLDMAP_H
#define TBSD_ROGUELIKE_WORLDMAP_H
#include <list>
#include <vector>
#include <string>
#include "../component/Position.h"


namespace tbsd {
  class WorldMap {
    class Tile {
    public:
      using TileType = char;
      TileType type;

      Tile() : type('.') {};
    };
    class BaseMap {
      class Chunk {
      public:
        static const int chunkXSize = 10;
        static const int chunkYSize = 10;
        int chunkZSize = 1;
      private:
        // vector3d[z][x][y]
        using Vector3d = std::vector<std::vector<std::vector<Tile>>>;
        Vector3d chunk;
      public:
        [[nodiscard]]
        Tile* at(size_t x, size_t y, size_t z) {
          return &chunk[z][y][x];
        }

        [[nodiscard]]
        const Tile* at(size_t x, size_t y, size_t z) const {
          return &chunk[z][y][x];
        }

        [[nodiscard]]
        std::string toString() const;
      };

      // type of map should allow fast insertion and remove of the first and
      // the last element for fast deserialization on demand and also have
      // fast random access iterator
      // TODO: replace with better class. Vector is very bad for it but it's fine for now
      std::vector<std::vector<Chunk>> map;

    public:
      /// Parameters must be 1 or greater
      BaseMap(size_t xChunksCount, size_t yChunksCount) : map(xChunksCount, std::list<Chunk>(yChunksCount)) {};

      BaseMap() : BaseMap(1, 1) {};

      [[nodiscard]]
      Tile* at(Position pos);
    };

    BaseMap mainMap; // main world map

  public:
    [[nodiscard]]
    Tile* at(Position pos);
  };
}


#endif //TBSD_ROGUELIKE_WORLDMAP_H
