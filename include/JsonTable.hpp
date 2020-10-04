//Copyright 2020 NickBBn

#ifndef INCLUDE_JSONTABLE_HPP
#define INCLUDE_JSONTABLE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <student.hpp>

class JsonTable {
 public:
  JsonTable();
  void set_spaces_number();
  std::string formatted(std::string str, int number);
  std::string print_table();
  void parse_file(std::string file_path);
  void parse_string(nlohmann::json json_data);
 private:
  std::vector <Student> _students;
  std::vector <int> _symbols;
};

#endif  // INCLUDE_JSONTABLE_HPP
