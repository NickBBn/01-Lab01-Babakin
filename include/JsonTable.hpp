//
// Created by nickmint on 9/28/20.
//

#ifndef JSONPARSER_JSONTABLE_HPP
#define JSONPARSER_JSONTABLE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <student.hpp>

class JsonTable {
 public:
  JsonTable();
  void set_spaces_number();
  std::string formatted (std::string str, int number);
  std::string print_table ();
  void parse_string (std::string file_path);
 private:
  std::vector <Student> _students;
  std::vector <int> _symbols;
};

#endif  // JSONPARSER_JSONTABLE_HPP
