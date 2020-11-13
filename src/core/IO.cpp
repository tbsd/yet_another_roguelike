#include <iostream>
#include "IO.h"
#include "Log.h"
#include <exception>


namespace tbsd {
  UserAction IO::parseUserAction(std::string data) {
    return UserAction(data);
  }

  std::string IO::getFromConsole() {
    if (std::cin.eof())
      return "eof";
    std::string input;
    std::getline(std::cin, input);
    return input;
  }

  ServerCommand IO::parseCommand(std::string_view data) {
    try {
      return CommandsMap.at(data.data());
    } catch (std::out_of_range &ex) {
      return Invalid;
    }
  }

//  std::string IO::getFromConsole()
}
