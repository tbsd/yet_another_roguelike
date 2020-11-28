#include <iostream>
#include <filesystem>
#include "core/Server.h"
#include "core/Game.h"
#include "core/Action.h"

/// Actions on application shut down
void onExit();
/// Create needed files and directories
void createFiles();

int main(int argc, char** argv) {
  tbsd::Action meh;
  std::cout << meh.time << std::endl;
  meh.time = 4;
  std::string str1("send");
  std::string str2("data");
  meh.args["command"] = str1.c_str();
  std::cout << meh.args << std::endl;
  createFiles();
  const int port = 4096;
  tbsd::Server server(port);
  server.run();
  tbsd::Game game(server);
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