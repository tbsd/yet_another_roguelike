#ifndef TILE_H
#define TILE_H
#include <list>
#include <memory>
#include "entityx/Entity.h"
#include "../component/Size.h"
#include "nlohmann/json.hpp"
#include "TileType.h"

namespace RoguesParty {
  /** Contains map cell propertys */
  class Tile {
    public: 
      TileType type;

    private:
      /// contains entities placed on this tile ordered by size
      /// TODO: replace with boost::flat_set
      std::list<std::shared_ptr<entityx::Entity>> objects;

    public:
      Tile(TileType type) : type(type) {}

      friend bool operator== (const Tile &lhs, const Tile &rhs) {
        if (lhs.type != rhs.type)
          return false;
        for (auto l = lhs.objects.cbegin(), r = rhs.objects.cbegin();
            l != lhs.objects.cend() && r != rhs.objects.cend(); ++l, ++r) {
          if (*l != *r)
            return false;
        }
        return true;
      }

      friend bool operator!= (const Tile &lhs, const Tile &rhs) {
        return !(lhs == rhs);
      }

      /** adds entity to the tile */
      void add(std::shared_ptr<entityx::Entity> object);

      /** get objects on this tile */
      const std::list<std::shared_ptr<entityx::Entity>> &getEntities();

      /** get objects on this tile with some data may be needed to draw it on 
       * map */
      nlohmann::json getData();
  };
}

#endif
