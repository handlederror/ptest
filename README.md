# PTest
PTest is a simple test library for use in C++ and use with C and C++.

## Installation
On POSIX system run `make` as root to install. If you are on Windows, there is no way to install it but you can use it by putting the headers to your projects include directory. For example `include/`.

## Usage
First, include the headers. If you installed it, use
```cpp
#include <color>
#include <vector>
#include <string>
#include <ptest/ptest.hpp>
```
to include. If you embedded header to project include by
```cpp
#include <vector>
#include <string>
#include "path/to/include/color"
#include "path/to/include/ptest.hpp"
```

After including the header, create `testing::PTest::Tester` and `colors::ColorPallet` objects. In the example, I'll create like
```cpp
const char* args[] = {"foo", "bar"};
colors::ColorPallet colorPallet;
testing::PTest::Tester tester = testing::PTest::Tester("tester", (char**)args, "cxx");
```

Now, create a test
```cpp
std::vector<std::string> test = {
    "std::cout << \"Hello, world!\" << std::endl;"
};
```
and set the required headers
```cpp
std::vector<std::string> includes = {
    "iostream"
};
```

After setting includes and creating the test, set the test job
```cpp
tester.testJob(includes, test);
```
and run the tests
```cpp
tester.runTestJob(colorPallet);
```

That's it! Enjoy.
