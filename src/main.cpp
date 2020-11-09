#include <iostream>
#include "core/Server.h"

/// Actions on application shut down
void onExit();

int main(int argc, char** argv) {
  const int port = 4096;
  tbsd::Server server(port);
  server.run();
  onExit();
  return 0;
}

void onExit() {
  std::cout << "Exiting..." << std::endl;
}
