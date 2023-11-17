#include "File.hpp"
#include <fstream>
#include <iostream>

GFiles::File::File(Path _filePath)
    : m_filePath(_filePath)
{
    m_read = false;
    load();
    m_buffer = new char[m_size + 1]; // + 1 to include str terminator char
}

bool GFiles::File::exists()
{
    return m_exists;
}

void GFiles::File::create()
{
    if (!m_exists)
    {
        m_file.open(m_filePath.path, std::ios::out | std::ios::trunc);
        m_file.close();
        load();
    }
}

void GFiles::File::load()
{
    loadData();
    if (m_exists)
    {
        m_file.open(m_filePath.path, std::ios::binary | std::ios::in | std::ios::out | std::ios::app | std::ios::ate);
    }
}

void GFiles::File::loadData()
{
    m_file.open(m_filePath.path);
    if (m_file.is_open())
    {
        m_exists = true;
        m_file.seekg(0, std::ios::end);
        m_size = m_file.tellg();
        m_file.seekg(0, std::ios::beg);
    }
    else
    {
        m_exists = false;
        m_size = -1;
    }
    m_file.close();
}

void GFiles::File::remove()
{
    if (m_exists)
    {
        m_file.close();
        m_exists = false;
        m_size = -1;
        std::remove(m_filePath.path.c_str());
    }
}

short GFiles::File::size()
{
    return m_size;
}

char *GFiles::File::read()
{
    if (!m_exists)
    {
        std::cerr << "Warning: File Doesn't exist. Cannot Read" << '\n';
        return nullptr;
    }

    m_file.seekg(0, std::ios::beg);
    m_file.read(m_buffer, m_size);
    m_read = true;
    m_buffer[m_size] = 0;

    return m_buffer;
}

void GFiles::File::write(std::string _buffer)
{
    remove();
    create();

    m_file.write(_buffer.c_str(), _buffer.length());
    m_file.close();
    load();
}

void GFiles::File::append(std::string _buffer)
{
    char *leftoverData = this->read();
    this->write(leftoverData + _buffer);
}

GFiles::File::~File()
{
    m_file.close();
    if (m_read)
    {
        delete[] m_buffer;
    }
}
