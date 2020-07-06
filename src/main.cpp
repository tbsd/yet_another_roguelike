#include <iostream>
#include "core/Server.h"
#include "core/Game.h"

using namespace RoguesParty;

/// Save game and user data
void onExit();

int main(int argc, char** argv) {
  Game game;
  Server server(game);
  server.run();
  onExit();
  return 0;
}

void onExit() {
  std::cout << "Exiting..." << std::endl;
}
