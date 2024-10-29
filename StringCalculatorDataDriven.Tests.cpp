#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>

using namespace std;

// Fixture Class
class StringCalculatorTest : public testing::Test {
protected:
    StringCalculator *calculator;
    vector<tuple<string, int, bool>> testCases;  // Added a boolean to indicate if an exception is expected

    void SetUp() override {
        calculator = new StringCalculator();
        // Initialize test cases with expected outcomes
        testCases = {
            {"", 0, false},       // Valid input: empty string
            {"0", 0, false},      // Valid input: zero
            {"1", 1, false},      // Valid input: single number
            {"1,2", 3, false},    // Valid input: simple addition
            {"1,-2", 0, false},   // Valid input: mixed positive and negative
            {"a,b", 0, true},     // Invalid input: non-numeric
            {"1,2,3,4,5", 15, false} // Valid input: multiple numbers
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

TEST_F(StringCalculatorTest, HandlesVariousInputs) {
    for (const auto& testCase : testCases) {
        verifyCalculation(get<0>(testCase), get<1>(testCase), get<2>(testCase));
    }
}
