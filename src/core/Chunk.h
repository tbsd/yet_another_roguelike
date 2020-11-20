#ifndef TBSD_ROGUELIKE_CHUNK_H
#define TBSD_ROGUELIKE_CHUNK_H
#include <vector>
#include <string>
#include "../component/Position.h"
#include "Tile.h"


namespace tbsd {
/// Contains single 2d piece of map
  class Chunk {
  public:
    using ID = unsigned long long;
    static constexpr size_t chunkXSize = 50;
    static constexpr size_t chunkYSize = 50;

  private:
    std::vector<std::vector<Tile>> chunk;
    ID nextId; // id for next created object
    ID id;

  public:
    Chunk() : id(nextId++) {};

    /// Returns true if chunk data is loaded to memory, false otherwise
    [[nodiscard]]
    bool isLoaded() const noexcept {
      return !chunk.empty();
    }

    /// Loads existing data if possible, create new data otherwise
    void load() {
      if (!isLoaded()) {
        chunk.assign(chunkXSize, std::vector<Tile>(chunkYSize, Tile()));
      }
    }

    [[nodiscard]]
    Tile *at(Coordinate x, Coordinate y) noexcept {
      return &chunk[x > 0 ? x : chunkXSize - x][y > 0 ? y : chunkYSize - y];
    }

    [[nodiscard]]
    const Tile *at(Coordinate x, Coordinate y) const noexcept {
      return &chunk[x > 0 ? x : chunkXSize - x][y > 0 ? y : chunkYSize - y];
    }

    [[nodiscard]]
    std::string toString() const;
  };
}


#endif //TBSD_ROGUELIKE_CHUNK_H
