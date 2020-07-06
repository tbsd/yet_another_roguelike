#ifndef USER_H
#define USER_H
#include <cstdint>
#include <string>

namespace RoguesParty {
  /** Contains player data */
  struct User {
    /** User unique identifier for current session */
    using Id = std::string; 

    Id id;

    User (Id id) : id(id) {}
  };
}

#endif
