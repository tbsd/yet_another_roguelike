//
// Created by subject on 11/13/20.
//

#ifndef TBSD_ROGUELIKE_SERVERCOMMANDS_H
#define TBSD_ROGUELIKE_SERVERCOMMANDS_H
#include <map>


namespace tbsd {
  namespace {
    struct strLess {
      bool operator()(const char *lhs, const char *rhs) const {
        return std::strcmp(lhs, rhs) < 0;
      }
    };
  }

/// Commands from server command line
  enum ServerCommand {
    Shutdown,
    Invalid,
    Empty
  };

/// Contains mapping for commands from server command line
const std::map<const char *, ServerCommand, strLess> CommandsMap {
      {"shut", Shutdown},
      {"eof", Shutdown},
      {"", Empty}
};
}


#endif //TBSD_ROGUELIKE_SERVERCOMMANDS_H
