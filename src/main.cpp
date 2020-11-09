#include <iostream>

/// Actions on application shut down
void onExit();

int main(int argc, char** argv) {
  onExit();
  return 0;
}

void onExit() {
  std::cout << "Exiting..." << std::endl;
}
