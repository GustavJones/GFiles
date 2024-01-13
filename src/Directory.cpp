#include "Directory.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

GFiles::Directory::Directory(const Path &_directoryPath)
    : m_directoryPath(&_directoryPath) {}

#ifdef unix
#include <sys/stat.h>

bool GFiles::Directory::exists() {
  struct stat st;
  if (stat(m_directoryPath->path.c_str(), &st) == 0) {
    if (st.st_mode & S_IFDIR != 0)
      return true;
  }
  return false;
}

void GFiles::Directory::createDirectory() {
  //  mkdir(m_directoryPath->path.c_str(), S_IRWXU | S_IRWXG | S_IROTH |
  //  S_IXOTH);
  std::string command = "mkdir ";
  command += m_directoryPath->path;
  std::cout << command << '\n';
  system(command.c_str());
}

void GFiles::Directory::removeDirectory() {
  std::string command = "rm -r ";
  command += m_directoryPath->path;
  std::cout << command << '\n';
  system(command.c_str());

  //  remove(m_directoryPath->path.c_str());
}

#elif _WIN32
#include <direct.h>
#include <windows.h>

bool GFiles::Directory::exists() {
  DWORD ftyp = GetFileAttributesA(m_directoryPath->path.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false; // something is wrong with your path!

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true; // this is a directory!

  return false; // this is not a directory!
}

void GFiles::Directory::createDirectory() {
  _mkdir(m_directoryPath->path.c_str());
}

void GFiles::Directory::removeDirectory() {
  _rmdir(m_directoryPath->path.c_str());
}

#endif

GFiles::Directory::~Directory() {}
