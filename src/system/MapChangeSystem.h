#ifndef MAPCHANGESYSTEM_H
#define MAPCHANGESYSTEM_H
#include "entityx/System.h"
#include "../event/MapChangeEvent.h"
#include <vector>
#include "../core/Map.h"
#include "../component/Position.h"
#include <memory>

namespace RoguesParty {
  class MapChangeSystem : public entityx::System<MapChangeSystem>,
  public entityx::Receiver<MapChangeSystem> {
    public:
      Map &map;

    public:
      MapChangeSystem(Map &map) : map(map) {};

      void configure(entityx::EventManager &em) {
        em.subscribe<MapChangeEvent>(*this);
      }

      void update(entityx::EntityManager &entities, entityx::EventManager &events,
          entityx::TimeDelta dt) {}

      void receive(const MapChangeEvent &event) {
        std::cout << event.action << std::endl;
        if (event.action["type"] == "move") {
          auto tmp = event.action["from"];
          Position from(tmp[0], tmp[1], tmp[2]);
          tmp = event.action["to"];
          Position to(tmp[0], tmp[1], tmp[2]);
          moveObject(event.target, from, to);
        } else if (event.action["type"] == "add") {
          auto tmp = event.action["position"];
          Position to(tmp[0], tmp[1], tmp[2]);
          setObject(event.target, to);
        } else if (event.action["type"] == "remove") {
          auto tmp = event.action["position"];
          Position from(tmp[0], tmp[1], tmp[2]);
          setObject(event.target, from);
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

      /** @returns json with info about each map cell */
      nlohmann::json getWholeMap() {
        std::list<nlohmann::json> changes;
        for (size_t i = 0; i < map.map.size(); ++i)
          for (size_t j = 0; j < map.map[0].size(); ++j)
            changes.emplace_back(nlohmann::json {
                {"type", map.map[i][j].type},
                {"x", i},
                {"y", j},
                {"z", 0}});
        std::cout << "ololo" << changes << std::endl;
        return {{"field", changes}};
      }

    private:
      /** adds pointer to object to selected tile */
      void setObject(std::shared_ptr<entityx::Entity> target, Position pos) {
        map.changedMap[pos.x][pos.y].add(target);
      }

      /** remove pointer to object from selected tile */
      void reomveObject(std::shared_ptr<entityx::Entity> target, Position pos) {
        map.changedMap[pos.x][pos.y].reomve(target);
      }

      /** move pointer from one tile to anther */
      void moveObject(std::shared_ptr<entityx::Entity> target, Position from, 
          Position to) {
        setObject(target, to);
        reomveObject(target, from);
      }

  };
}

#endif
