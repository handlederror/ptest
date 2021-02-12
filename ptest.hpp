#pragma once
#ifndef PTEST_PTEST_HPP
#define PTEST_PTEST_HPP

#include <color>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sys>

namespace testing
{
    namespace PTest
    {
        class Tester
        { public:
            std::string name;
            std::string version;
            std::vector<std::string> argumentVector;
            std::vector<std::string> includes;
            std::vector<std::string> test;

            Tester(std::string name, char* argumentVector[], std::string version) {
                this->name = name;
                
                if (version == "cxx" || version == "c") {
                    this->version = version;
                } else {
                    this->version = "cxx";
                }
                
                for (int index = 0; index < sizeof(argumentVector) / sizeof(argumentVector[0]); index++)
                {
                    this->argumentVector.push_back(argumentVector[index]);
                }
            }

            void testJob(std::vector<std::string> includes, std::vector<std::string> test) {
                for (std::string element : test)
                {
                    this->test.push_back(element);
                } for (std::string element : includes) {
                    this->includes.push_back(element);
                }
            }

            void runTestJob(colors::ColorPallet& colorPallet) {
                for (int index = 0; index < 20; index++)
                {
                    std::cout << (const char*)"=";

                    if (index == 10) {
                        std::cout << " PTest C++ Tester ";
                    }
                } std::cout << std::endl << std::endl;

                colors::Colored::printColored(colorPallet, "yellow");
                std::cout << " - Running test job..." << std::endl << std::endl << std::endl;

                if (this->version == "cxx") {
                    std::ofstream file ("a.test.cpp");

                    for (int index = 0; index < this->includes.size(); index++)
                    {
                        file << "#include \"" << this->includes.at(index) << "\"\n";
                    }
                    
                    file << "int main(int argc, char* argv[]) {";

                    for (int index = 0; index < this->test.size(); index++) {
                        file << this->test.at(index);
                    }
                    
                    file << "}";

                    file.close();
                } else {
                    if (this->version == "c") {
                        std::ofstream file ("a.test.c");

                        for (int index = 0; index < this->includes.size(); index++)
                        {
                            file << "#include \"" << this->includes.at(index) << "\"\n";
                        }
                        
                        file << "int main(int argc, char* argv[]) {";

                        for (int index = 0; index < this->test.size(); index++) {
                            file << this->test.at(index);
                        }
                        
                        file << "}";

                        file.close();
                    }
                }

                std::string cmd_args;

                for (int index = 0; index < this->argumentVector.size(); index++) {
                    cmd_args = cmd_args + argumentVector[index] + " ";
                }

                if (this->version == "cxx") {
                    std::cout << sys::exec(std::string("g++ ./a.test.cpp && ./a.out " + cmd_args + " && rm ./a.out").c_str()) << std::endl;
                } else {
                    if (this->version == "c") {
                        std::cout << sys::exec(std::string("gcc ./a.test.cpp && ./a.out " + cmd_args + " && rm ./a.out").c_str()) << std::endl;
                    }
                }

                colors::Colored::printColored(colorPallet, "green");
                std::cout << " -- Test job done (may have errors) -- " << std::endl << std::endl;
            }
        };
    }
}

#endif
