#include <iostream>
#include "IO.h"
#include "Log.h"
#include <exception>
#include <fstream>


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

  std::vector<char> IO::readFromFile(std::string_view path) {
    std::ifstream inFile(path.data(), std::ios::binary | std::ios::in);
    inFile.seekg(0, std::ios::end);
    size_t size = inFile.tellg();
    inFile.seekg(0, std::ios::beg);
    std::vector<char> rawData;
    rawData.reserve(size);
    rawData.insert(rawData.cbegin(),
                   std::istreambuf_iterator<char>(inFile),
                       std::istreambuf_iterator<char>());
    inFile.close();
    return rawData;
  }

}
