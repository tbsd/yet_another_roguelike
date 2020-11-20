#ifndef TBSD_ROGUELIKE_IO_H
#define TBSD_ROGUELIKE_IO_H
#include <string>
#include "UserAction.h"
#include "ServerCommand.h"
#include <string_view>


namespace tbsd {
/// Handles input parsing and output encoding
  class IO {
  public:
    /// Get input from console
    std::string getFromConsole();

    /// Parses user requests
    UserAction parseUserAction(std::string data);

    /// Parses input from console on server side
    ServerCommand parseCommand(std::string_view data);

    /// Reads whole file in binary mode
   std::vector<char> readFromFile(std::string_view path);
  };
}

#endif //TBSD_ROGUELIKE_IO_H
