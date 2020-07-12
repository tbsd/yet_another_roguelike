#ifndef USER_H
#define USER_H
#include <cstdint>
#include <string>
#include <vector>
#include "../core/Tile.h"
#include "../core/Coordinate.h"

namespace RoguesParty {
  /** User unique identifier for current session */
  using Id = std::string; 

  /** Contains player data */
  struct User {

    Id id;
    /// Map data that user already have
    std::vector<std::vector<Tile>> mapCache;

    User (Id id, Coordinate mapXSize = 50, Coordinate mapYSize = 50) : id(id) {
      mapCache.resize(mapYSize, std::vector<Tile>(mapXSize, TileType::GROUND));
    }
  };
}

#endif
