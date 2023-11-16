#include "GFiles/Directory.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    // Tests Directory Objects
    GFiles::Path p1("C:\\CXXProjects\\GFiles\\tests\\testCreate", '\\');
    GFiles::Directory d1(p1);
    d1.createDirectory();
    // d1.removeDirectory();
    return 0;
}