#ifndef TBSD_ROGUELIKE_USER_H
#define TBSD_ROGUELIKE_USER_H
#include "ID.h"
#include "entityx/Entity.h"
#include "server/ws/ws_session.h"
#include <vector>

namespace tbsd {
  struct User {
    ID id = 0;
    CppServer::WS::WSSession* session;
    std::vector<entityx::Entity> owned; // Collection of objects owned by user

    explicit User(CppServer::WS::WSSession* session) : session(session) {};
  };
}

#endif //TBSD_ROGUELIKE_USER_H
