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
            char* args[1] = {"--no-argument"};

            return this->testJob(args);
        }

        int runTests(char* args[]) {
            return this->testJob(args);
        }
    };
}
