#ifndef TBSD_ROGUELIKE_IO_H
#define TBSD_ROGUELIKE_IO_H
#include <string>
#include <filesystem>
#include "UserAction.h"
#include "ServerCommand.h"
#include <string_view>


namespace tbsd {
/// Handles input parsing and output encoding
  class IO {
  public:
    /// Save files path
//    static constexpr const char* const SavePath = "saves/";
    static const std::filesystem::path SavePath;

    /// Get input from console
    std::string getFromConsole();

    /// Parses user requests
    UserAction parseUserAction(std::string data);

    /// Parses input from console on server side
    ServerCommand parseCommand(std::string_view data);

    /// Reads whole file in binary mode
   std::vector<char> readFromFile(std::filesystem::path filePath);
  };
}

#endif //TBSD_ROGUELIKE_IO_H
