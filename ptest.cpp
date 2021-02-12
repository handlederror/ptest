#include "ptest.hpp"

#include <sys>

TEST("BuildTest", "BuildCXX") {
    #include <iostream>

    std::cout << sys::exec("g++ ./main.cpp && ./a.out && rm ./a.out") << std::endl;

    return 0;
} END_TEST;

int main(int argc, char* argv[]) {
    char* args[1] = {argv[1]};

    return testing::PseudoTest.runTests(args);
}
