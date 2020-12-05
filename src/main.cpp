#include <iostream>
#include <filesystem>
#include "core/Server.h"
#include "core/RealtimeGame.h"

/// Actions on application shut down
void onExit();
/// Create needed files and directories
void createFiles();

int main(int argc, char** argv) {
  createFiles();
  const int port = 4096;
  tbsd::Server server(port);
  server.run();
  tbsd::RealtimeGame game(server, std::chrono::milliseconds(1000), 10);
  game.run();
  onExit();
  return 0;
}

void onExit() {
  std::cout << "Exiting..." << std::endl;
}

void createFiles() {
  try {
    std::filesystem::create_directory(tbsd::IO::SavePath);
  } catch (std::filesystem::filesystem_error& ex) {
    tbsd::Log::send("Can not create necessary files", tbsd::Log::FatalError);
  }
}