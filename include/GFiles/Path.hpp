#pragma once
#include <string>

namespace GFiles {
class Path {
public:
  std::string path;
  Path();
  Path(std::string _path);

  bool isfile();
  std::string extension();
  std::string filename();

  ~Path();
};
} // namespace GFiles
