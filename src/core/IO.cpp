#include <iostream>
#include "IO.h"
#include "Log.h"
#include <exception>
#include <fstream>


namespace tbsd::IO {
  UserAction parseUserAction(std::string data) {
    return UserAction(data);
  }

  std::string getFromConsole() {
    if (std::cin.eof())
      return "eof";
    std::string input;
    std::getline(std::cin, input);
    return input;
  }

  ServerCommand parseCommand(std::string_view data) {
    try {
      return CommandsMap.at(data.data());
    } catch (std::out_of_range &ex) {
      return Invalid;
    }
  }

  std::vector<char> readFromFile(std::filesystem::path filePath) {
    std::ifstream inFile(filePath, std::ios::binary | std::ios::in);
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

  std::filesystem::path getChunkPath(ID id) {
    //TODO: remove to_string() when id would be char *
    return SavePath / (std::filesystem::path(std::to_string(id) + ChunkSuffix));
  }
}
