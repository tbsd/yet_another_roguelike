#ifndef TBSD_ROGUELIKE_WORLDMAP_H
#define TBSD_ROGUELIKE_WORLDMAP_H
#include <list>
#include <vector>
#include <string>
#include <array>
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

      /// Contains single 2d piece of map
      class Chunk {
      public:
        static constexpr size_t chunkXSize = 50;
        static constexpr size_t chunkYSize = 50;
      private:
        using Plane = std::array<std::array<Tile, chunkYSize>, chunkXSize>;
        Plane chunk;
      public:
        [[nodiscard]]
        Tile* at(Coordinate x, Coordinate y) noexcept {
          return &chunk[x > 0 ? x : chunkXSize - x][y > 0 ? y : chunkYSize - y];
        }

        [[nodiscard]]
        const Tile* at(Coordinate x, Coordinate y) const noexcept {
          return &chunk[x > 0 ? x : chunkXSize - x][y > 0 ? y : chunkYSize - y];
        }

        [[nodiscard]]
        std::string toString() const;
      };

      // type of map should allow fast insertion and remove of the first and
      // the last element for fast deserialization on demand and also have
      // fast random access iterator
      // TODO: replace with better solution. Vector is very bad for it but it's fine for now
      std::vector<std::vector<Chunk>> map;

    public:
      /// Parameters must be 1 or greater
      BaseMap(size_t xChunksCount, size_t yChunksCount) : map(xChunksCount, std::vector<Chunk>(yChunksCount)) {};

      BaseMap() : BaseMap(1, 1) {};

      [[nodiscard]]
      Tile* at(Position pos);
    };

    BaseMap mainMap; // main world map

  public:
    // TODO: make it work with negative Coordinates
    [[nodiscard]]
    Tile* at(Position pos);
  };
}


#endif //TBSD_ROGUELIKE_WORLDMAP_H
