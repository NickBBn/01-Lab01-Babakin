//
// Created by nickmint on 9/28/20.
//

#include "JsonTable.hpp"

#include <fstream>
JsonTable::JsonTable(const std::vector<Student>& students)
    : _students(students) {}

std::string JsonTable::print_table()
{
  std::string info;
  for (auto i = _students.begin();i<_students.cend();i++)
  {
   // nlohmann::json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;
    info += i->name_string() + " ";
    info += i->group_string() + " ";
    info += i->avg_string() + " ";
    info += i->debt_string() + " ";
  }
  return info;
}
void JsonTable::parse_string(std::string file_path)
{
  std::ifstream file(file_path);
  if (!file) {
    throw std::runtime_error{"unable to open json: " + file_path};
  }

  nlohmann::json data;
  file >> data;
  int count=0;
  for (auto item = data.at("items").cbegin();
       item<data.at("items").cend();item++)
  {
    _students.push_back(Student());
    _students[count].from_json(item.value());
    count++;
  }

  //std::string tmp = jstring;
}
JsonTable::JsonTable() {}
