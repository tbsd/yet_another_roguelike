#include "Server.h"
#include <iostream>

namespace tbsd {
  Server::~Server() {
    server->Stop();
    service->Stop();
  }

  void Server::run() {
    service->Start();
    server->Start();
    Log::send("Server is running...");
  }
}
