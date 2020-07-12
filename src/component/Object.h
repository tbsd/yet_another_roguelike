#ifndef OBJECT_H
#define OBJECT_H
#include "../core/TileType.h"

namespace RoguesParty {
  struct Object {
    TileType type;

    Object(TileType type) : type(type) {}
  };
}

#endif
