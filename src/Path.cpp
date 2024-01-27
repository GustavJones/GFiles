#include "Path.hpp"
#include "File.hpp"
#include <string>

GFiles::Path::Path() : path("") {}

bool GFiles::Path::isfile() {
  GFiles::File file(*this);
  return file.exists();
}

GFiles::Path::Path(std::string _path) : path(_path) {}

std::string GFiles::Path::extension() {
  std::string output;

  if (!isfile()) {
    return "";
  }

  int i = path.length() - 1;
  while (path[i] != '.') {
    output += path[i];

    if (i == 0) {
      return "";
    }

    i--;
  }

  return output;
}

std::string GFiles::Path::filename() {
  std::string output;

  int i = path.length() - 1;
  while (path[i] != '/' && i != -1) {
    output += path[i];
    i--;
  }

  return output;
}

GFiles::Path::~Path() {}
