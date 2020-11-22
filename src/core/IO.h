#ifndef TBSD_ROGUELIKE_IO_H
#define TBSD_ROGUELIKE_IO_H
#include <string>
#include <filesystem>
#include "UserAction.h"
#include "ServerCommand.h"
#include <string_view>
#include "ID.h"


/// Handles input parsing and output encoding
namespace tbsd::IO {
  /// Save files path
  const std::filesystem::path SavePath = "saves/";
  /// Suffix for chunk save files
  constexpr const char* const ChunkSuffix = ".ch";

  /// Get input from console
  std::string getFromConsole();

  /// Parses user requests
  UserAction parseUserAction(std::string data);

  /// Parses input from console on server side
  ServerCommand parseCommand(std::string_view data);

  /// Reads whole file in binary mode
  std::unique_ptr<char[]> readFromFile(std::filesystem::path filePath);

  /// Writes to file in binary mode
  void writeToFile(std::filesystem::path filePath, void* data, size_t size);

  /// Returns chunk save file path
  std::filesystem::path getChunkPath(ID id);
}

#endif //TBSD_ROGUELIKE_IO_H
