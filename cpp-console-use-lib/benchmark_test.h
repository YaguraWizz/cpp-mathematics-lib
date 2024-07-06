#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include "cpp-combinatorics-lib.h"

using namespace std;
using namespace std::chrono;

struct TestResult {
    string testName;
    string operationName;
    long long averageTime;
};

// Function to measure the execution time of addition operation
static TestResult testAddition(const UnsignedInteger& a, const UnsignedInteger& b, int numTests, const string& testName, const string& operationName) {
    auto start = high_resolution_clock::now();
    UnsignedInteger result = 0;
    for (int i = 0; i < numTests; ++i) {
        result = a + b;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start).count() / numTests;

    return { testName, operationName, duration };
}

// Function to measure the execution time of subtraction operation
static TestResult testSubtraction(const UnsignedInteger& a, const UnsignedInteger& b, int numTests, const string& testName, const string& operationName) {
    auto start = high_resolution_clock::now();
    UnsignedInteger result = 0;
    for (int i = 0; i < numTests; ++i) {
        result = a - b;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start).count() / numTests;

    return { testName, operationName, duration };
}

// Function to measure the execution time of multiplication operation
static TestResult testMultiplication(const UnsignedInteger& a, const UnsignedInteger& b, int numTests, const string& testName, const string& operationName) {
    auto start = high_resolution_clock::now();
    UnsignedInteger result = 0;
    for (int i = 0; i < numTests; ++i) {
        result = a * b;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start).count() / numTests;

    return { testName, operationName, duration };
}

// Function to measure the execution time of division operation
static TestResult testDivision(const UnsignedInteger& a, const UnsignedInteger& b, int numTests, const string& testName, const string& operationName) {
    auto start = high_resolution_clock::now();
    UnsignedInteger result = 0;
    for (int i = 0; i < numTests; ++i) {
        result = a / b;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start).count() / numTests;

    return { testName, operationName, duration };
}

static void benchmark_test_UnsignedInteger() {
    const int numTests = 1;  // Number of repetitions for averaging

    cout << "### Performance Report for UnsignedInteger Operations ###" << endl;

    vector<TestResult> results;
    vector<string> msg;
    try {
        for (int cycle = 1; cycle <= 5; ++cycle) {
            string num1_str(pow(10, cycle), '9');
            string num2_str(pow(10, cycle), '8');

            UnsignedInteger a(num1_str);
            UnsignedInteger b(num2_str);

            msg.push_back("Cycle " + to_string(cycle) + ": Testing with numbers of size " + to_string(num1_str.length()) + " digits");

            // Testing addition operation
            results.push_back(testAddition(a, b, numTests, "Test " + to_string(cycle), "Addition"));

            // Testing subtraction operation
            results.push_back(testSubtraction(a, b, numTests, "Test " + to_string(cycle), "Subtraction"));

            // Testing multiplication operation
            results.push_back(testMultiplication(a, b, numTests, "Test " + to_string(cycle), "Multiplication"));

            // Testing division operation
            results.push_back(testDivision(a, b, numTests, "Test " + to_string(cycle), "Division"));
        }
    }
    catch (const std::exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown exception caught." << endl;
    }

    // Output all results at the end
    for (size_t cycle = 0; cycle < msg.size(); ++cycle) {
        cout << msg[cycle] << endl;
        for (int j = 0; j < 4; ++j) {
            int index = cycle * 4 + j;
            cout << "- " << results[index].testName << ": " << results[index].operationName << endl;
            cout << "  - Average time: " << results[index].averageTime << " ms" << endl;
        }
    }
}


