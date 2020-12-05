#include "TurnbasedGame.h"

namespace tbsd {
  void TurnbasedGame::run() {
    mainLoop([this] {processAllActions();});
  }

  void TurnbasedGame::processAllActions() {
    // TODO: make it parallel for actions with the same Action::time
    // TODO: make it stop if no players actions left
    Unit maxAp = 0;
    while (!actions.empty()) {
      auto action = actions.top();
      maxAp = action.time;
      processAction(action);
      actions.pop();
    }
    apTime += maxAp;
  }

}