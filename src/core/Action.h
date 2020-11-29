#ifndef TBSD_ROGUELIKE_ACTION_H
#define TBSD_ROGUELIKE_ACTION_H
#include "Unit.h"
#include <map>

namespace tbsd {
  /// Stores action type, arguments and time to complete this action
  class Action {

  public:
    Unit time; // Time to complete action
    std::map<const char*, const char*> args; // Stores command type and arguments

    explicit Action(Unit time = 0) : time(time), args() {};

    /// Relation by time for sorting in priority order
    friend bool operator>(const Action& lhs, const Action& rhs) {
      return lhs.time > rhs.time;
    }
    struct Greater {
      bool operator()(const Action& lhs, const Action& rhs) {
        return lhs > rhs;
      }
    };
  };
}

#endif //TBSD_ROGUELIKE_ACTION_H
