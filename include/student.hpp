// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <any>
#include <iostream>
#include <string>
#include "nlohmann/json.hpp"
#include "student.hpp"

class Student {
 public:
  Student(){}
  Student(const std::string& name, const std::any& group, const std::any& avg,
          const std::any& debt);
  virtual ~Student();
  auto get_name(const nlohmann::json& j) -> std::string;
  auto get_avg(const nlohmann::json& j) -> std::any;
  auto get_group(const nlohmann::json& j) -> std::any;
  auto get_debt(const nlohmann::json& j) -> std::any;
 public:
  void from_json(const nlohmann::json& j);
  std::string name_string() const;
  std::string group_string() const;
  std::string avg_string() const;
  std::string debt_string() const;
 private:
  std::string _name;
  std::any _group;
  std::any _avg;
  std::any _debt;
};

#endif // INCLUDE_HEADER_HPP_
