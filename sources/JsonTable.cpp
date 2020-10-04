//Copyright 2020 NickBBn

#include "JsonTable.hpp"

#include <fstream>
JsonTable::JsonTable()//const std::vector<Student>& students
    : _students() {
  //for (short i=0; i<4; i++) _symbols.push_back(5);
          _symbols.push_back(4);
          _symbols.push_back(5);
          _symbols.push_back(3);
          _symbols.push_back(4);
}

std::string JsonTable::print_table()
{
  set_spaces_number();
  std::string separator = "";
  for (int i = 0;  i < static_cast<int>(_symbols.size()); i++){
    separator += "|";
    for (int t = 0; t < _symbols[i]+2; t++){
      separator += "-";
    }
  }
  std::string words [4] =  {"name", "group", "avg", "debt"};
  std::string title = "|";
  for (int i = 0;  i < static_cast<int>(_symbols.size()); i++){
    title += formatted(words[i], _symbols[i]);
  }
  title += "\n";
  separator += "|\n";
  std::string info = title + separator;
  for (auto i = _students.begin(); i<_students.cend(); i++)
  {
    info += "|" + formatted(i->name_string(), _symbols[0]);
    info += formatted(i->group_string(), _symbols[1]);
    info += formatted(i->avg_string(), _symbols[2]);
    info += formatted(i->debt_string(), _symbols[3]) + "\n";
    info += separator;
  }
  return info;
}

void JsonTable::parse_string(nlohmann::json data)
{
  int count = 0;
  if (!data.at("items").is_array())
    throw std::string("Incorrect json file: \"items\" is not array");
  if (!data.at("_meta").at("count").is_number_integer()){
    throw std::string("Incorrect json file: wrong \"_meta\" type");
  } else if (data.at("_meta").at("count").get<uint64_t>() !=
             data.at("items").get<std::vector<nlohmann::json>>().size()) {
    throw std::string("Incorrect json file: \"items\" "
        "size doesn't match value of \"_meta\" at \"count\"");
  }
  for (auto item = data.at("items").cbegin();
       item < data.at("items").cend(); item++)
  {
    _students.push_back(Student());
    _students[count].from_json(item.value());
    count++;
  }

  //std::string tmp = jstring;
}

void JsonTable::set_spaces_number()
{
  for (auto i=_students.cbegin(); i < _students.cend(); i++) {
    if (static_cast<int>(i->name_string().size()) > _symbols[0])
      _symbols[0] = i->name_string().size();  // two extra spaces
    if (static_cast<int>(i->group_string().size()) > _symbols[1])
      _symbols[1] = i->group_string().size();
    if (static_cast<int>(i->avg_string().size()) > _symbols[2])
      _symbols[2] = i->avg_string().size();
    if (static_cast<int>(i->debt_string().size()) > _symbols[3])
      _symbols[3] = i->debt_string().size();
  }
}

std::string JsonTable::formatted(std::string str, int number) {
  std::string result = " ";
  result += str;
  for (int i=0; i < number-static_cast<int>(str.size()); i++)
  {
    result+=" ";
  }
  result += " |";
  return result;
}
void JsonTable::parse_file(std::string file_path)
{
  std::ifstream file(file_path, std::ifstream::in);
  if (!file) {
    throw std::string("Could not find json file by path: " + file_path);
  }
  nlohmann::json data;
  file >> data;
  parse_string(data);
}
