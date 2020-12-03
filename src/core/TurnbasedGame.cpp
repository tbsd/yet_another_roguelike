#include "TurnbasedGame.h"

namespace tbsd {
  void TurnbasedGame::run() {
    mainLoop([this] {processActions();});
  }
}