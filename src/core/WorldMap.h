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

    /// Contains map data
    class BaseMap {
      //TODO: make it add chunks for z dimension on demand
      //TODO: make it load/unload chunks on demand

      /// Contains single 2d piece of map
      class Chunk {
      public:
        static constexpr size_t chunkXSize = 50;
        static constexpr size_t chunkYSize = 50;
      private:
        std::vector<std::vector<Tile>> chunk;
        static unsigned long long nextId; // id for next created object
        unsigned long long id;
      public:
        Chunk() : id(nextId++) {};

        /// Returns true if chunk data is loaded to memory, false otherwise
        [[nodiscard]]
        bool isLoaded() const noexcept {
          return !chunk.empty();
        }

        /// Loads existing data if possible, create new data otherwise
        void load() {
          if (isLoaded()) {
            chunk.assign(chunkXSize, std::vector<Tile>(chunkYSize, Tile()));
          }
        }

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

      //TODO: add z levels
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
