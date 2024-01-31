#include "Directory.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

GFiles::Directory::Directory(const Path &_directoryPath)
    : m_directoryPath(&_directoryPath) {}

#ifdef unix
#include <dirent.h>
#include <sys/stat.h>

bool GFiles::Directory::exists() {
  struct stat st;
  if (stat(m_directoryPath->path.c_str(), &st) == 0) {
    if ((st.st_mode & S_IFDIR) != 0)
      return true;
  }
  return false;
}

void GFiles::Directory::createDirectory() {
  //  mkdir(m_directoryPath->path.c_str(), S_IRWXU | S_IRWXG | S_IROTH |
  //  S_IXOTH);

  if (exists()) {
    std::cout << "Directory Exists" << '\n';
    return;
  }
  std::string command = "mkdir ";
  command += m_directoryPath->path;
  system(command.c_str());
}

void GFiles::Directory::removeDirectory() {
  if (!exists()) {
    std::cout << "Directory Doesnt Exist" << '\n';
    return;
  }
  std::string command = "rm -r ";
  command += m_directoryPath->path;
  system(command.c_str());

  //  remove(m_directoryPath->path.c_str());
}

std::vector<GFiles::Path> GFiles::Directory::listDirectory() {
  std::vector<GFiles::Path> output;
  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir(m_directoryPath->path.c_str())) != nullptr) {
    while ((ent = readdir(dir)) != nullptr) {
      std::string filename(ent->d_name);
      if (filename != "." && filename != "..") {
        output.push_back((GFiles::Path)filename);
      }
    }
    closedir(dir);
  } else {
    std::cerr << "Could not open directory" << std::endl;
    return std::vector<GFiles::Path>();
  }

  return output;
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
