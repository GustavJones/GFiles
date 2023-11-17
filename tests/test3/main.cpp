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

    GFiles::File f1(GFiles::Path("C:\\CXXProjects\\GFiles\\tests\\test3\\test.json", '\\'));
    f1.create();

    std::cout << f1.read() << "\n";
    f1.write("Write\n");
    f1.append("Append\n");

    std::cout << f1.read() << "\n";

    return 0;
}