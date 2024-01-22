#include "File.hpp"
#include <fstream>
#include <iostream>

GFiles::File::File(Path _filePath, bool _isBinary)
    : m_filePath(_filePath), m_exists(false), m_bufferCreate(false),
      m_isBinary(_isBinary) {
  load();
}

bool GFiles::File::exists() { return m_exists; }

void GFiles::File::create() {
  if (!m_exists) {
    if (m_isBinary) {
      m_file.open(m_filePath.path, std::ios::binary | std::ios::out);
    } else {
      m_file.open(m_filePath.path, std::ios::out);
    }
    m_file.close();
  } else {
    std::cout << "File exists" << '\n';
  }
}

void GFiles::File::load() {
  if (m_isBinary) {
    m_file.open(m_filePath.path,
                std::ios::binary | std::ios::in | std::ios::out);
  } else {
    m_file.open(m_filePath.path, std::ios::in | std::ios::out);
  }

  if (m_file.is_open()) {
    m_exists = true;

    m_file.seekg(0, std::ios::beg);
    int begin = m_file.tellg();

    m_file.seekg(0, std::ios::end);
    int end = m_file.tellg();

    m_size = end - begin;
    m_file.seekg(0, std::ios::beg);
  } else {
    m_exists = false;
    m_size = -1;
  }
  m_file.close();

  if (m_bufferCreate) {
    delete[] m_buffer;
  }

  if (m_size > 0) {
    m_bufferCreate = true;
    m_buffer = new char[m_size];
  }
}

void GFiles::File::remove() {
  if (m_exists) {
    m_file.close();
    std::remove(m_filePath.path.c_str());
  } else {
    std::cout << "File Doesnt Exist" << '\n';
  }
}

int GFiles::File::size() { return m_size; }

char *GFiles::File::read() {
  load();

  if (!m_exists) {
    std::cerr << "Warning: File Doesn't exist. Cannot Read" << '\n';
    return nullptr;
  }
  if (m_isBinary) {
    m_file.open(m_filePath.path, std::ios::binary | std::ios::in);

    if (m_size > 0) {
      m_file.seekg(0, std::ios::beg);
      m_file.read(m_buffer, m_size);
      // m_buffer[m_size - 1] = 0;
    } else {
      m_buffer = 0;
    }
  } else {
    m_file.open(m_filePath.path, std::ios::in);

    std::string line;
    while (std::getline(m_file, line)) {
      m_bufferStr += line + '\n';
    }

    return (char *)m_bufferStr.c_str();
  }

  m_file.close();

  return m_buffer;
}

void GFiles::File::write(char *_buffer, int _len) {
  remove();
  create();

  if (m_isBinary) {
    m_file.open(m_filePath.path, std::ios::binary | std::ios::out);
  } else {
    m_file.open(m_filePath.path, std::ios::out);
  }

  char *buffer = _buffer;

  m_file.write(buffer, _len);
  m_file.close();
  load();
}

void GFiles::File::append(char *_buffer, int _len) {
  load();

  if (m_isBinary) {
    m_file.open(m_filePath.path,
                std::ios::binary | std::ios::out | std::ios::app);
  } else {
    m_file.open(m_filePath.path, std::ios::out | std::ios::app);
  }

  const char *buffer = _buffer;

  m_file.write(buffer, _len);
  m_file.close();
  load();
}

GFiles::Path GFiles::File::path() { return m_filePath; }

GFiles::File::~File() {
  m_file.close();
  if (m_bufferCreate) {
    delete[] m_buffer;
  }
}
