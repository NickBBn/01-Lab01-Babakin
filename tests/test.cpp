// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>

#include "JsonTable.hpp"
#include "student.hpp"
TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Example_tests, First_try)
{
  int c=3;
  Student student;
  int b = student.test_fun(c);
  EXPECT_EQ(b, c);
}

TEST(Project_tests, Bscic_print)
{
  std::string file_path = "/home/nickmint/CLionProjects/Lab1repository/example.json";
  JsonTable table;
  table.parse_string(file_path);
  std::string tmp = table.print_table();
  EXPECT_EQ(tmp, "something");
}