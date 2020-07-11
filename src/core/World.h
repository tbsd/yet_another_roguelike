#ifndef WORLD_H
#define WORLD_H
#include "Map.h"

namespace RoguesParty {
  /** Contains world maps and manages transitions beetween them */
  class World {
    public:
      Map map;
  };
}

#endif
