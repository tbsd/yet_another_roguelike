//
// Created by subject on 11/10/20.
//

#include "Log.h"
#include <iostream>
#include <iomanip>

namespace tbsd {
  const char* const Log::messageLabel[] = {"Message", "Received", "Warning", "Error", "FatalError"};

  void Log::send(std::string_view msg, Log::Type type) {
    static std::time_t t = std::time(nullptr);
    static std::tm tm = *std::localtime(&t);
    std::cout << "["<< std::put_time(&tm, "%d.%m.%y %H:%M:%S") << "|" << messageLabel[type] << "] " << msg << std::endl;
  }
}
