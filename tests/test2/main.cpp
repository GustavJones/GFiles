#include "GFiles/Directory.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
// Tests Directory Objects
#ifdef _WIN32
    GFiles::Path p1("C:\\CXXProjects\\GFiles\\tests\\testCreate", '\\');
#elif unix
    GFiles::Path p1("/home/gustavjones/Documents/GFiles/tests/testCreate", '\\');
#endif
    GFiles::Directory d1(p1);
    // d1.createDirectory();
    d1.removeDirectory();
    return 0;
}