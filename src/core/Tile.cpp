#include "Tile.h"
#include "../component/Object.h"

namespace RoguesParty {
  void Tile::add(std::shared_ptr<entityx::Entity> object) {
    auto volume = object->component<Size>()->volume;
    auto i = objects.cbegin();
    for (; i != objects.cend(); ++i) {
      if (**i == *object)
        return;
      if ((*i)->component<Size>()->volume > volume) 
        break;
    }
    objects.insert(i, object);
  }

  void Tile::reomve(std::shared_ptr<entityx::Entity> object) {
    objects.remove(object);
  }

  const std::list<std::shared_ptr<entityx::Entity>> &Tile::getEntities() {
    return objects;
  }

  nlohmann::json Tile::getData() {
    std::list<nlohmann::json> result;
    for (auto i = objects.cbegin(); i != objects.cend(); ++i) {
      /// TODO: add more object properties
      result.emplace_back(nlohmann::json {
          {"type", (*i)->component<Object>()->type},
          {"size", (*i)->component<Size>()->volume},
          {"effects", {}}
          });
    }
    return nlohmann::json {
      {"type", type},
        {"objects", result}
    };
  }
}
