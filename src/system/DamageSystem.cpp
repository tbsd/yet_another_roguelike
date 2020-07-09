#include "DamageSystem.h"
#include "../component/Damageable.h"

namespace RoguesParty {
  void DamageSystem::receive(const DamageEvent &damageEvent) {
    int resultingDamage = damageEvent.damage;
    /// TODO: add resists and other effects handling
    entityx::Entity &target = damageEvent.damage;
    if (target.has_component<Damageable>()) {
      auto &damagable = damageEvent.target.component<Damageable>();
      damagable.hp -= resultingDamage;
      if (damagable.hp <= 0)
        damagable.dead = true;
    }
  }
}
