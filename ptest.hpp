#pragma once

#include <string>
#include <iostream>

#define END_TEST };} namespace testing { testing::Test PseudoTest; }
#define TEST(test_case_name, test_name) namespace testing { class Test : public testing::PTest { public: int testJob(char* args[])
#define RUN_ALL_TESTS testing.runTests()

namespace testing
{
    class PTest
    { public:
        int testJob(char* args[]) {
            std::cout << "Hello, world!" << std::endl;

            return 0;
        }

        int runTests() {
            std::cout << "========== PTest Tester Job ==========" << std::endl << std::endl;

            int testStatus;
            char* args[1] = {"--no-argument"};

            std::cout << " - Running test job..." << std::endl;

            testStatus = this->testJob(args);

            if (testStatus != 0) {
                std::cout << std::endl << " -- Test job done (exited with errors) -- " << std::endl << std::endl;
            } else {
                std::cout << std::endl << " -- Test job done (no errors) -- " << std::endl << std::endl;
            }

            return testStatus;
        }

        int runTests(char* args[]) {
            std::cout << "========== PTest Tester Job ==========" << std::endl << std::endl;

            int testStatus;

            std::cout << " - Running test job..." << std::endl << std::endl;

            testStatus = this->testJob(args);

            if (testStatus != 0) {
                std::cout << std::endl << " -- Test job done (exited with errors) -- " << std::endl << std::endl;
            } else {
                std::cout << std::endl << " -- Test job done (no errors) -- " << std::endl << std::endl;
            }

            return testStatus;
        }
    };
}
