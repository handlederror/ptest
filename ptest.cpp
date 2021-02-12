#include "ptest.hpp"

#include <color>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    const char* args[] = {""};
    testing::PTest::Tester tester = testing::PTest::Tester("tester", (char**)args, "cxx");

    std::vector<std::string> includes = {
        "sys",
        "iostream"
    };

    std::vector<std::string> test = {
        "std::cout << sys::exec(\"g++ main.cpp && ./a.out && rm ./a.out\") << std::endl;"
    };

    colors::ColorPallet colorPallet;

    tester.testJob(includes, test);
    tester.runTestJob(colorPallet);
}
