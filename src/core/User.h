#ifndef TBSD_ROGUELIKE_USER_H
#define TBSD_ROGUELIKE_USER_H
#include "ID.h"
#include "entityx/Entity.h"
#include "server/ws/ws_session.h"
#include <vector>

namespace tbsd {
  struct User {
    ID id;
    CppServer::WS::WSSession session;
    std::vector<entityx::Entity> owned; // Collection of objects owned by user
  };
}

#endif //TBSD_ROGUELIKE_USER_H
