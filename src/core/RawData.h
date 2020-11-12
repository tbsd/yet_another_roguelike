#ifndef TBSD_ROGUELIKE_RAWDATA_H
#define TBSD_ROGUELIKE_RAWDATA_H
#include "server/ws/ws_server.h"
#include <string>


namespace tbsd {
/// Contains pointer to user session and data from that session
  struct RawData {
    CppServer::WS::WSSession *session;
    std::string data;
  };
}


#endif //TBSD_ROGUELIKE_RAWDATA_H
