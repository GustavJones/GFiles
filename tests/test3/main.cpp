#include <iostream>
#include "GFiles/File.hpp"

int main(int argc, char const *argv[])
{
    // GFiles::File f1(GFiles::Path("C:\\CXXProjects\\GFiles\\tests\\test3\\test.json", '\\'));
    // // std::cout << f1.exists() << '\n';
    // f1.create();
    // // f1.remove();

    // GFiles::File f2(GFiles::Path("C:\\CXXProjects\\GFiles\\tests\\test3\\test2.txt", '\\'));
    // f2.write("Rewrite test, it works");

    // // std::cout << f1.size() << '\n';
    // std::cout << f1.read() << '\n'
    //           << '\n';

    // f1.append("\nAppend test");
    // std::cout << f1.read() << '\n'
    //           << '\n';

    GFiles::File f1(GFiles::Path("C:\\CXXProjects\\GFiles\\build\\Debug\\tests\\test2\\test2.exe", '\\'), true);
    GFiles::File f2(GFiles::Path("C:\\CXXProjects\\GFiles\\build\\Debug\\tests\\test2\\test2-Copy.exe", '\\'), true);

    f2.create();

    char *buffer = f1.read();
    std::cout << buffer << "\n";

    f2.write(buffer, f1.size());

    return 0;
}