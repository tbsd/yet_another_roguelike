#include "Action.h"
#include "Direction.h"

namespace tbsd {
  namespace {
    struct InvalidEnumException : public std::runtime_error {
      InvalidEnumException() : std::runtime_error("Invalid enum value") {};
    };

    // assumes that 0 and _last values present in the enum
    template <class E>
    bool isInEnumRange(int i) {
      return i >= 0 && i < static_cast<int>(E::_last);
    }

    void parseDirection(const nlohmann::json& jsonAction, std::vector<std::any>& result) {
      int val = jsonAction.at("direction");
      result.emplace_back(static_cast<Direction>(val));
    }

    // TODO:  add parseEnum
    template <class T>
    void parseSimpleClass(const nlohmann::json& jsonAction, std::vector<std::any>& result, std::string_view fieldName) {
      result.emplace_back(jsonAction.at(fieldName.data()));
    }

    void parseActionType(const nlohmann::json& jsonAction, std::vector<std::any>& result) {
      int val = jsonAction.at("action");
      if (!isInEnumRange<Action::Type>(val))
        throw InvalidEnumException();

      auto actionType = static_cast<Action::Type>(val);
      result.emplace_back(actionType);

      switch (actionType) {
        case Action::Type::Move:
          parseDirection(jsonAction, result);
          break;
      }
    }
  }

  void Action::setData(std::string_view rawJson) {
    nlohmann::json jsonAction = nlohmann::json::parse(rawJson);
    data.reserve(jsonAction.size());
    parseActionType(jsonAction, data);
  }
}