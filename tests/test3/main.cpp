#include <iostream>
#include "GFiles/File.hpp"

int main(int argc, char const *argv[])
{
    GFiles::File f1(GFiles::Path("C:\\CXXProjects\\GFiles\\build\\Debug\\tests\\test2\\test2.exe", '\\'), true);
    GFiles::File f2(GFiles::Path("C:\\CXXProjects\\GFiles\\build\\Debug\\tests\\test2\\test2-Copy.exe", '\\'), true);

    int size = f1.size();
    char *buffer = f1.read();
    size = f1.size();

    f2.create();
    f2.write(buffer, size);

    GFiles::File f3(GFiles::Path("C:\\CXXProjects\\GFiles\\build\\Debug\\tests\\test3\\test3.txt", '\\'));
    GFiles::File f4(GFiles::Path("C:\\CXXProjects\\GFiles\\build\\Debug\\tests\\test3\\test3-Copy.txt", '\\'));

    f3.create();
    f4.create();

    std::string buffer1 = f3.read();
    int size1 = f3.size();

    // std::string bufferStr = "this is a test buffer";
    // f4.write((char *)bufferStr.c_str(), bufferStr.length());

    std::cout << buffer1 << '\n';
    f4.write((char *)buffer1.c_str(), buffer1.length());

    return 0;
}