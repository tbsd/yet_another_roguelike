#ifndef TBSD_ROGUELIKE_ACTION_H
#define TBSD_ROGUELIKE_ACTION_H
#include "Unit.h"
#include <map>
#include <string>

namespace tbsd {
  /// Stores action type, arguments and time to complete this action
  struct Action {
    Unit time; // Time to complete action
    std::map<std::string, std::string> args; // Stores command type and arguments

    explicit Action(Unit time = 0) : time(time), args() {};

    /// Relation by time for sorting in priority order
    friend bool operator>(const Action& lhs, const Action& rhs) {
      return lhs.time > rhs.time;
    }
  };
}

#endif //TBSD_ROGUELIKE_ACTION_H
