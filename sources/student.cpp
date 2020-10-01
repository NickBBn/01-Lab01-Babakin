// Copyright 2018 Your Name <your_email>

#include <student.hpp>

using nlohmann::json;

Student::Student(const std::string& name, const std::any& group,
                 const std::any& avg, const std::any& debt)
    : _name(name),
      _group(group),
      _avg(avg),
      _debt(debt) {}

int Student::test_fun(const int a)
{
  return a;
}

Student::~Student() {}

void Student::from_json(const json& j)
{
  _name = get_name(j.at("name"));
  _group = get_group(j.at("group"));
  _avg = get_avg(j.at("avg"));
  _debt = get_debt(j.at("debt"));
}
auto Student::get_name(const json& j) -> std::string
{
  if (j.is_string()) return j.get<std::string>();
  return "invalid type";
}
auto Student::get_avg(const json& j) -> std::any
{
  if (j.is_null()) return nullptr;
  if (j.is_string()) return j.get<std::string>();
  if (j.is_number_float()) return j.get<float>();
  if (j.is_number_integer()) return j.get<int>();
  return "invalid type";
}
auto Student::get_group(const json& j) -> std::any
{
  if (j.is_string()) return j.get<std::string>();
  if (j.is_number_integer()) return j.get<int>();
  if (j.is_number_float()) return j.get<float>();
  return "invalid type";
}
auto Student::get_debt(const json& j) -> std::any
{
  if (j.is_null()) return nullptr;
  if (j.is_string()) return j.get<std::string>();
  if (j.is_array()) return j.get<std::vector<std::string>>();
  return "invalid type:json fault";
}

std::string Student::name_string() const
{
  return _name;
}
std::string Student::group_string() const
{
  if (_group.type() == typeid(int)) return std::to_string(std::any_cast<int>(_group));
  if (_group.type() == typeid(float)) return std::to_string(std::any_cast<float>(_group));
  if (_group.type() == typeid(std::string)) return std::any_cast<std::string>(_group);
  return "invalid type";
}
std::string Student::avg_string() const
{
  if (_avg.type() == typeid(int)) return std::to_string(std::any_cast<int>(_avg));
  if (_avg.type() == typeid(float_t)){
    std::string tmp = std::to_string(std::any_cast<float>(_avg));
    while (tmp.at(tmp.size()-1)=='0') tmp=tmp.substr(0, tmp.size()-1);
    return tmp;
   // return std::to_string(std::any_cast<float>(_avg));
  }
  if (_avg.type() == typeid(std::string)) return std::any_cast<std::string>(_avg);
  return "invalid type";
}
std::string Student::debt_string() const
{
  if (_debt.type() == typeid(int)) return std::to_string(std::any_cast<int>(_debt));
  if (_debt.type() == typeid(std::string)) return std::any_cast<std::string>(_debt);
  if (_debt.type() == typeid(std::vector<std::string>))
  {
    int size;
    size = std::any_cast<std::vector<std::string>>(_debt).size();
  //  return "this debt is vector";
    return std::to_string(size);
  }
  if (_debt.type() == typeid(std::nullptr_t)) return "null";
  return "invalid debt type";
}