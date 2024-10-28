#include "StringCalculator.h"
#include <gtest/gtest.h>

//TEST(TestSuiteName, TestCaseName)
TEST(string_calculator_add,when_passed_a_single_number_returns_0_for_Empty){
  //Arrange
  StringCalculator objUnderTest;
  string input="";
  int expectedValue=0;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
  }

TEST(string_calculator_add,when_passed_a_single_number_returns_0_for_0){
  //Arrange
  StringCalculator objUnderTest;
  string input="0";
  int expectedValue=0;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
  }

TEST(string_calculator_add,when_passed_a_single_number_returns_1_for_1){
  //Arrange
  StringCalculator objUnderTest;
  string input="1";
  int expectedValue=1;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
  }
 
TEST(string_calculator_add,when_passed_two_comma_delimited_numbers){
  //Arrange
  StringCalculator objUnderTest;
  string input="1,7";
  int expectedValue=8;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
  }
TEST(string_calculator_add,when_passed_multiple_comma_delimited_numbers){
  //Arrange
  StringCalculator objUnderTest;
  string input="1,4,3";
  int expectedValue=8;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  EXPECT_EQ(expectedValue,actualValue);
  }
TEST(string_calculator_add,when_passed__newline_and_comma){
  //Arrange
  StringCalculator objUnderTest;
  string input="1\n2,3";
  int expectedValue=6;

  //Act
  int actualValue=objUnderTest.Add(input);
  //ASSERT
  EXPECT_EQ(expectedValue,actualValue);
  }
TEST(string_calculator_add,when_passed_a_delimiter){
  //Arrange
  StringCalculator objUnderTest;
  string input="//;\n3;5";
  int expectedValue=8;

  //Act
  int actualValue=objUnderTest.Add(input);
  //ASSERT
  EXPECT_EQ(expectedValue,actualValue);
  }
TEST(string_calculator_add, when_passed_negative_numbers){
  //Arrange
  StringCalculator objUnderTest;
  string input="-5,-9";
  int expectedValue="Negatives not allowed: -5,-9";

  //Act
  int actualValue=objUnderTest.Add(input);
  //ASSERT
  EXPECT_EQ(expectedValue,actualValue);
  }
TEST(string_calculator_add, when_passed_numbers_over_1000){
  //Arrange
  StringCalculator objUnderTest;
  string input=""87,1987501,13"";
  int expectedValue="100";

  //Act
  int actualValue=objUnderTest.Add(input);
  //ASSERT
  EXPECT_EQ(expectedValue,actualValue);
  }
TEST(string_calculator_add,  when_passed_multicharacter_delimiter){
  //Arrange
  StringCalculator objUnderTest;
  string input="//7*5^^6//";
  int expectedValue="18";

  //Act
  int actualValue=objUnderTest.Add(input);
  //ASSERT
  EXPECT_EQ(expectedValue,actualValue);
  }
TEST(string_calculator_add,  when_passed_multiple_delimiters){
  //Arrange
  StringCalculator objUnderTest;
  string input="//[*][%]\n4*2%3";
  int expectedValue="9";

  //Act
  int actualValue=objUnderTest.Add(input);
  //ASSERT
  EXPECT_EQ(expectedValue,actualValue);
  }
