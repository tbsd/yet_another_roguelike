#ifndef TBSD_ROGUELIKE_ACTION_H
#define TBSD_ROGUELIKE_ACTION_H
#include "Unit.h"
#include "../component/Position.h"
#include <any>
#include <nlohmann/json.hpp>

namespace tbsd {
  /// Stores action type, arguments and time to complete this action
  class Action {
  public:
    enum class Type {Move, Connected, Disconnected, _last};

    std::vector<std::any> data;
    Unit time; // Time to complete action

    explicit Action(Unit time = 0) : time(time) {};

    explicit Action(std::string_view data, Unit time = 0) : time(time) {
      setData(data);
    }

    /// Relation by time for sorting in priority order
    friend bool operator>(const Action& lhs, const Action& rhs) {
      return lhs.time > rhs.time;
    }
    struct Greater {
      bool operator()(const Action& lhs, const Action& rhs) {
        return lhs > rhs;
      }
    };

    template<class... Ts>
    void setData(Ts... args) {
      size_t count = 0;
      ((args, ++count), ...);
      data.reserve(count);
      (data.emplace_back(args), ...);
    }

    void setData(std::string_view rawJson);

    [[nodiscard]]
    Type getType() const {
      return std::any_cast<Type>(data[0]);
    }
  };
}

#endif //TBSD_ROGUELIKE_ACTION_H
