#include "ptest.hpp"

#include <sys>

TEST("BuildTest", "BuildCXX") {
    #include <iostream>

    std::cout << sys::exec("g++ ./main.cpp && ./a.out && rm ./a.out") << std::endl;

    return 0;
} END_TEST;

int main() {
    return RUN_ALL_TESTS;
}
