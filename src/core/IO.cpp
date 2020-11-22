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

  std::unique_ptr<char[]> readFromFile(std::filesystem::path filePath) {
    std::ifstream inFile(filePath, std::ios::binary | std::ios::in);
    if (inFile.is_open()) {
      inFile.seekg(0, std::ios::end);
      size_t size = inFile.tellg();
      inFile.seekg(0, std::ios::beg);
      auto rawData = std::make_unique<char[]>(size);
      inFile.read(rawData.get(), size);
      inFile.close();
      return rawData;
    } else
      return {};
  }

  std::filesystem::path getChunkPath(ID id) {
    //TODO: remove to_string() when id would be char *
    return SavePath / (std::filesystem::path(std::to_string(id) + ChunkSuffix));
  }

  void writeToFile(std::filesystem::path filePath, void* data, size_t size) {
    std::ofstream oFile(filePath, std::ios::binary | std::ios::out);
    if (oFile.is_open()) {
      oFile.write(static_cast<const char*>(data), size);
      oFile.close();
    } else {
      throw std::runtime_error("Can't write to " + filePath.relative_path().string());
    }
  }
}
