//
// Created by subject on 11/10/20.
//

#include "Log.h"
#include <iostream>

namespace tbsd {
  const char* const Log::messageLabel[] = {"Message", "Received", "Warning", "Error", "FatalError"};

  void Log::send(std::string_view msg, Log::Type type) {
    std::cout << "[" << messageLabel[type] << "] " << msg << std::endl;
  }
}
