#include <iostream>
#include "IO.h"


namespace tbsd {
  UserAction IO::parseUserAction(std::string data) {
    return UserAction(data);
  }

  std::string IO::getFromConsole() {
    std::string input;
    std::getline(std::cin, input);
    return input;
  }

//  std::string IO::getFromConsole()
}
