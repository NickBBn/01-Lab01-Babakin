#ifndef INCLUDE_ANY_AND_JSON_SUPPORT_HPP_
#define INCLUDE_ANY_AND_JSON_SUPPORT_HPP_

#include <nlohmann/json.hpp>
#include <any>
#include <string>
#include <vector>

namespace nlohmann {
template <>
struct adl_serializer<std::any>{
  static void to_json(json& j, const std::any& any_var)
  {
    if (any_var.type() == typeid(std::string)) {
      j = std::any_cast<std::string>(any_var);
    } else if (any_var.type() == typeid(int)) {
      j = std::any_cast<int>(any_var);
    } else if (any_var.type() == typeid(float)) {
      j = std::any_cast<float>(any_var);
    } else if (any_var.type() == typeid(std::vector<std::string>)) {
      j = std::any_cast<std::vector<std::string>>(any_var);
    } else {
      j = nullptr;
    }
  }
  static void from_json(const json& j, std::any& any_var)
  {
    if (j.is_null()) any_var = nullptr;
    if (j.is_string()) any_var = j.get<std::string>();
    if (j.is_number_integer()) any_var = j.get<int>();
    if (j.is_number_float()) any_var = j.get<float>();
    if (j.is_array())
    {
      std::vector <std::string> tmpv;
      for (json::const_iterator i = j.cbegin();i<j.cend();i++)
      {
        std::string tmpstr = i.value();
        tmpv.push_back(tmpstr);
      }
      any_var = tmpv;
    }
  }
};
}
#endif