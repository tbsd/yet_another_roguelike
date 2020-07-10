#include "DamageSystem.h"
#include "../component/Damageable.h"

namespace RoguesParty {
  void DamageSystem::receive(const DamageEvent &damageEvent) {
    int resultingDamage = damageEvent.damage;
    /// TODO: add resists and other effects handling
    auto target = damageEvent.target;
    if (target.has_component<Damageable>()) {
      auto damagable = target.component<Damageable>();
      damagable->hp -= resultingDamage;
      if (damagable->hp <= 0)
        damagable->dead = true;
    }
  }
}
