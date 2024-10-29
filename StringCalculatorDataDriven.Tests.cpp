#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>

using namespace std;


class StringCalculatorTest : public testing::Test {
protected:
    StringCalculator *calculator;
    vector<tuple<string, int, bool>> testCases;  

    void SetUp() override {
        calculator = new StringCalculator();
       
        testCases = {
            {"", 0, false},       
            {"0", 0, false},     
            {"1", 1, false},      
            {"1,2", 3, false},    
            {"1,-2", 0, false},   
            {"a,b", 0, true},    
            {"1,2,3,4,5", 15, false} 
        };
    }

    void TearDown() override {
        delete calculator;
    }

    void verifyCalculation(const string& input, int expected, bool expectException) {
        if (expectException) {
            ASSERT_THROW(calculator->Add(input), invalid_argument);
        } else {
            int result = calculator->Add(input);
            ASSERT_EQ(result, expected);
        }
    }
};
