#include "GFiles/Directory.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
// Tests Directory Objects
#ifdef _WIN32
  GFiles::Path p1("C:\\CXXProjects\\GFiles\\tests\\testCreate", '\\');
#elif unix
  GFiles::Path p1("./TestProjectasdfasdfasdfasf");
  GFiles::Path p2(p1.path + "/src");
#endif
  GFiles::Directory d1(p1);
  GFiles::Directory d2(p2);
  d1.createDirectory();
  d2.createDirectory();
  d1.removeDirectory();
  std::cout << d1.exists() << '\n';

  std::cin.get();

  return 0;
}
