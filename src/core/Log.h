#ifndef TBSD_ROGUELIKE_LOGGER_H
#define TBSD_ROGUELIKE_LOGGER_H
#include <string_view>

namespace tbsd {
  class Log {
  public:
    enum Type {
      Message, Received, Warning, Error, FatalError
    };
  private:
    static const char *const messageLabel[];
  public:
    static void send(std::string_view msg, Type type = Type::Message);
  };
}

#endif //TBSD_ROGUELIKE_LOGGER_H
