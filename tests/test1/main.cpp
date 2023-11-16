#include "GFiles/Path.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    // Tests Path Objects

    GFiles::Path p1("C:\\CXXProjects\\GFiles\\include", '\\');
    GFiles::Path p2("/usr/local/games");
    GFiles::Path p3("/usr/local/CXX a test/dir");
    GFiles::Path p4("C:\\CXXProjects\\GFiles\\include\\Path.hpp", '\\');
    std::cout << p1.isfile() << '\n';
    std::cout << p4.isfile() << '\n';
    std::cout << p4.path << '\n';
    return 0;
}