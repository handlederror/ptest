#include "ptest.hpp"

#include <color>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    const char* args[] = {""};
    testing::PTest::Tester tester = testing::PTest::Tester("tester", (char**)args, "cxx");

    std::vector<std::string> includes = {
        "string",
        "iostream"
    };

    std::vector<std::string> test = {
        "std::string hello = \"Hello, world!\";",
        "std::cout << hello << std::endl;"
    };

    colors::ColorPallet colorPallet;

    tester.testJob(includes, test);
    tester.runTestJob(colorPallet);
}
