#pragma once
#include <string>

namespace GFiles {
class Path {
private:
  char m_delimiter;
  bool m_isFile;

public:
  std::string path;
  Path();
  Path(std::string _path, char _delimiter = '/');

  bool isfile();
  std::string extension();
  std::string filename();

  ~Path();
};
} // namespace GFiles
