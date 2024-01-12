#include "Path.hpp"
#include <stdexcept>

GFiles::Path::Path() : path(""), m_delimiter('/') {}

GFiles::Path::Path(std::string _path, char _delimiter)
    : path(_path), m_delimiter(_delimiter) {
  //  short lastDelimiterPos = -1;

  // Check for empty directories
  if (path == "") {
    throw std::out_of_range("Path object is empty");
  }

  // // Check for directories with a starting space
  // if (path.find(m_delimiter + ' ') != -1)
  // {
  //     throw std::invalid_argument("Path contains directory that starts with a
  //     space");
  // }

  // Check for double usage of delimiter
  // if (path.find(m_delimiter + m_delimiter) != -1) {
  //  throw std::invalid_argument("Path contains an empty directory");
  // }

  // Last delimiter
  //  lastDelimiterPos = path.find_last_of(m_delimiter);

  //  if (lastDelimiterPos == -1) {
  //  for (int i = 0; i < path.length(); i++) {
  //    if (path[i] == '.') {
  //      m_isFile = true;
  //    }
  //  }
  //}
  //  else {
  //    // Check for . and test for file
  //    for (int i = lastDelimiterPos; i < path.length(); i++) {
  //      if (path[i] == '.') {
  //        m_isFile = true;
  //      }
  //    }
  //  }
}

// bool GFiles::Path::isfile() { return m_isFile; }

std::string GFiles::Path::extension() {
  //  if (!m_isFile) {
  //    return "";
  //  }

  int periodPos;
  std::string output;

  for (int i = path.length() - 1; i >= 0; i--) {
    if (path[i] == '.') {
      periodPos = i;
    }
  }

  for (int i = periodPos + 1; i < path.length(); i++) {
    output += path[i];
  }

  return output;
}

std::string GFiles::Path::filename() {
  //  if (!m_isFile) {
  //    return "";
  //  }

  int periodPos;
  int delimiterPos = -1;
  std::string output;

  for (int i = path.length() - 1; i >= 0; i--) {
    if (path[i] == '.') {
      periodPos = i;
    }

    if (path[i] == m_delimiter) {
      delimiterPos = i;
      break;
    }
  }

  for (int i = delimiterPos + 1; i < periodPos; i++) {
    output += path[i];
  }

  return output;
}

GFiles::Path::~Path() {}
