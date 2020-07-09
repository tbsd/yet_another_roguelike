#ifndef DAMAGESYSTEM_H
#define DAMAGESYSTEM_H 
#include "entityx/System.h"
#include "../event/DamageEvent.h"

namespace RoguesParty {
  class DamageSystem : public entityx::System<DamageSystem>, 
  public entityx::Receiver<DamageSystem> {
    public: 
      void configure(entityx::EventManager &em) {
        em.subscribe<DamageEvent>(*this);
      }

      void update(entityx::EntityManager &entities, entityx::EventManager &events,
          entityx::TimeDelta dt) {}

      void receive(const DamageEvent &damageEvent);
      
  };
}

#endif
