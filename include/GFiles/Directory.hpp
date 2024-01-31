#pragma once
#include "Path.hpp"
#include <vector>

namespace GFiles {
class Directory {
private:
  const Path *m_directoryPath;

public:
  Directory(const Path &_directoryPath);

  bool exists();

  void createDirectory();
  void removeDirectory();

  std::vector<Path> listDirectory();

  ~Directory();
};
} // namespace GFiles
