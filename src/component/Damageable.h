#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H
#include <cstdint>

namespace RoguesParty { 
  struct Damageable {
    int hp;
    bool dead;

    Damageable(int hp, bool dead = false) : hp(hp), dead(dead) {}
  };
}

#endif
