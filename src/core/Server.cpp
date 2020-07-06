#include "Server.h"
#include <iostream>

namespace RoguesParty {
  Server::~Server() {
    server->Stop();
    service->Stop();
  }

  void Server::run() {
    service->Start();
    server->Start();
    std::cout << "Press Enter to stop the server or '!' to restart the server..." << std::endl;
    std::string line;
    while (getline(std::cin, line))
    {
      if (line.empty())
        break;

      // Restart the server
      if (line == "!")
      {
        std::cout << "Server restarting...";
        server->Restart();
        std::cout << "Done!" << std::endl;
        continue;
      }

      // Multicast admin message to all sessions
      line = "(admin) " + line;
      server->MulticastText(line);
    }

  }
}
