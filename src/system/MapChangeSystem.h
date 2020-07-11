#ifndef MAPCHANGESYSTEM_H
#define MAPCHANGESYSTEM_H
#include "entityx/System.h"
#include "../event/MapChangeEvent.h"
#include <vector>
#include "../core/Map.h"

namespace RoguesParty {
  class MapChangeSystem : public entityx::System<MapChangeSystem>,
  public entityx::Receiver<MapChangeSystem> {
    public:
      Map map;

    public:
      MapChangeSystem(Map map) : map(map) {};

      void configure(entityx::EventManager &em) {
        em.subscribe<MapChangeEvent>(*this);
      }

      void update(entityx::EntityManager &entities, entityx::EventManager &events,
          entityx::TimeDelta dt) {}

      void receive(const MapChangeEvent &event) {
        std::cout << event.action << std::endl;
        if (event.action["type"] == "move") {
          auto from = event.action["from"];
          auto to = event.action["to"];
          addChange(from[0], from[1], TileType::GROUND);
          addChange(to[0], to[1], TileType::HUMAN);
        }
      };

      void update() {
        for (size_t i = 0; i < map.map.size(); ++i) {
          for (size_t j = 0; j < map.map[0].size(); ++j) {
            map.previousMap[i][j] = map.map[i][j];
            map.map[i][j] = map.changedMap[i][j];
          }
        }
      }

      /** Returns difference between current map state and changes made */
      nlohmann::json delta() {
        std::list<nlohmann::json> changes;
        for (size_t i = 0; i < map.map.size(); ++i) {
          for (size_t j = 0; j < map.map[0].size(); ++j) 
            if (map.previousMap[i][j] != map.map[i][j]) {
              std::cout << "diff" << std::endl;
              changes.emplace_back(nlohmann::json {
                  {"type", map.map[i][j]},
                  {"x", i},
                  {"y", j},
                  {"z", 0}});
            }
        }
        std::cout << "ololo" << changes << std::endl;
        return {{"field", changes}};
      }

    private:
      void addChange(Coordinate x, Coordinate y, TileType change) {
        map.changedMap[x][y] = change;
      }

  };
}

#endif
