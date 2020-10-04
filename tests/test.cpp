// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include "JsonTable.hpp"
#include "student.hpp"
TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Valid_input, file1)
{
  std::string file_path = "../JSONfiles/example1.json";
  JsonTable table;
  table.parse_file(file_path);
  std::string result = table.print_table();
  std::cout << result;
  std:: string expected_table =
      "| name          | group  | avg  | debt |\n"
      "|---------------|--------|------|------|\n"
      "| Ivanov Petr   | 1      | 4.25 | null |\n"
      "|---------------|--------|------|------|\n"
      "| Sidorov Ivan  | 31     | 4    | C++  |\n"
      "|---------------|--------|------|------|\n"
      "| Pertov Nikita | IU8-31 | 3.33 | 3    |\n"
      "|---------------|--------|------|------|\n";
  EXPECT_EQ(result, expected_table);
}

TEST(Valid_input, file2)
{
  std::string file_path = "../JSONfiles/example2.json";
  JsonTable table;
  table.parse_file(file_path);
  std::string result = table.print_table();
  std::cout << result;
  std:: string expected_table =
      "| name          | group  | avg  | debt    |\n"
      "|---------------|--------|------|---------|\n"
      "| Antonov Oleg  | 1.2    | 5    | Windows |\n"
      "|---------------|--------|------|---------|\n"
      "| Smorodin Dima | 9      | 4    | null    |\n"
      "|---------------|--------|------|---------|\n"
      "| Kirov Slava   | RK6-31 | 4.95 | 2       |\n"
      "|---------------|--------|------|---------|\n";
  EXPECT_EQ(result, expected_table);
}

TEST(Invalid_input, invalid_name)
{
  std::string file_path = "../JSONfiles/invalid_name.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  } catch (std::string& error) {
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result, "Incorrect json file: invalid name");
}

TEST(Invalid_input, invalid_group)
{
  std::string file_path = "../JSONfiles/invalid_group.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  } catch (std::string& error) {
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result, "Incorrect json file: invalid group");
}

TEST(Invalid_input, invalid_avg)
{
  std::string file_path = "..\\JSONfiles\\invalid_avg.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  } catch (std::string& error) {
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result, "Incorrect json file: invalid avg");
}

TEST(Invalid_input, invalid_debt)
{
  std::string file_path = "../JSONfiles/invalid_debt.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  } catch (std::string& error) {
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result, "Incorrect json file: invalid debt");
}

TEST(Invalid_input, invalid_path)
{
  std::string file_path = "../JSONfiles/somepath.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  }
  catch (std::string& error){
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result,
            "Could not find json file by path: ../JSONfiles/somepath.json");
}

TEST(Invalid_input, invalid_items)
{
  std::string file_path = "../JSONfiles/not_array.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  }
  catch (std::string& error) {
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result, "Incorrect json file: \"items\" is not array");
}

TEST(Invalid_input, invalid_meta)
{
  std::string file_path = "../JSONfiles/invalid_meta.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  }
  catch (std::string& error) {
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result, "Incorrect json file: wrong \"_meta\" type");
}

TEST(Invalid_input, invalid_size)
{
  std::string file_path = "../JSONfiles/invalid_size.json";
  JsonTable table;
  std::string result;
  try {
    table.parse_file(file_path);
  }
  catch (std::string& error) {
    std::cout << error << std::endl;
    result = error;
  }
  EXPECT_EQ(result, "Incorrect json file: "
            "\"items\" size doesn't match value of \"_meta\" at \"count\"");
}
