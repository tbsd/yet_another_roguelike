#ifndef TBSD_ROGUELIKE_IO_H
#define TBSD_ROGUELIKE_IO_H
#include <string>
#include "UserAction.h"


namespace tbsd {
/// Handles input parsing and output encoding
  class IO {
  public:
    /// Get input from console
    std::string getFromConsole();

    /// Parses user requests
    UserAction parseUserAction(std::string data);
  };
}

#endif //TBSD_ROGUELIKE_IO_H
