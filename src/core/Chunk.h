#ifndef TBSD_ROGUELIKE_CHUNK_H
#define TBSD_ROGUELIKE_CHUNK_H
#include <vector>
#include <string>
#include <fstream>
#include "../component/Position.h"
#include "ChunkData_generated.h"
#include "IO.h"
#include "Log.h"


namespace tbsd {
/// Contains single 2d piece of map
  class Chunk {
  public:
    static constexpr Coordinate chunkXSize = 50;
    static constexpr Coordinate chunkYSize = 50;

  private:
    static ID nextId; // id for next created object
    ID id;
    ChunkDataT data;

  public:
    Chunk() : id(nextId++), data() {};

    /// Returns true if chunk data is loaded to memory, false otherwise
    [[nodiscard]]
    bool isLoaded() const noexcept {
      return !data.x.empty();
    }

    /// Loads existing data if possible, create new data otherwise
    void load();

    /// Stores chunk data to disk
    void store();

    [[nodiscard]]
    Tile* at(Coordinate x, Coordinate y) noexcept {
      return &data.x[x >= 0 ? x : chunkXSize + x]->y[y >= 0 ? y : chunkYSize + y];
    }

    [[nodiscard]]
    const Tile* at(Coordinate x, Coordinate y) const noexcept {
      return &data.x[x >= 0 ? x : chunkXSize + x]->y[y >= 0 ? y : chunkYSize + y];
    }

    [[nodiscard]]
    std::string toString() const;
  };
}


#endif //TBSD_ROGUELIKE_CHUNK_H
