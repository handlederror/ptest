#include <ptest/ptest.hpp>

TEST("PTestTest", "Test PTest") {
	#include <iostream>

	std::cout << "Hello, world!" << std::endl;

	return 0;
} END_TEST;

int main() {
	return RUN_ALL_TESTS;
}

