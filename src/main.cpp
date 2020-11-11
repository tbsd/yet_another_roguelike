#include <iostream>
#include "core/Server.h"
#include "core/Game.h"

/// Actions on application shut down
void onExit();

int main(int argc, char** argv) {
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
