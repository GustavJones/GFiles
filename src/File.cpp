#include "File.hpp"
#include <fstream>
#include <iostream>

GFiles::File::File(Path _filePath)
    : m_filePath(_filePath), m_exists(false), m_bufferCreate(false)
{
    load();
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
    m_file.open(m_filePath.path, std::ios::binary | std::ios::in | std::ios::out | std::ios::app | std::ios::ate);
    if (m_file.is_open())
    {
        m_exists = true;

        m_file.seekg(0, std::ios::beg);
        int begin = m_file.tellg();

        m_file.seekg(0, std::ios::end);
        int end = m_file.tellg();

        m_size = end - begin;
        m_file.seekg(0, std::ios::beg);
    }
    else
    {
        m_exists = false;
        m_size = -1;
    }
    m_file.close();

    if (m_bufferCreate)
    {
        delete[] m_buffer;
    }

    m_bufferCreate = true;
    m_buffer = new char[m_size];
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

int GFiles::File::size()
{
    load();
    return m_size;
}

char *GFiles::File::read()
{
    load();

    if (!m_exists)
    {
        std::cerr << "Warning: File Doesn't exist. Cannot Read" << '\n';
        return nullptr;
    }
    m_file.open(m_filePath.path, std::ios::binary | std::ios::in);

    if (m_size > 0)
    {
        m_file.seekg(0, std::ios::beg);
        m_file.read(m_buffer, m_size);
        m_buffer[m_size] = 0;
    }
    else
    {
        m_buffer = 0;
    }

    m_file.close();

    return m_buffer;
}

void GFiles::File::write(char *_buffer, int _len)
{
    remove();
    create();
    m_file.open(m_filePath.path, std::ios::binary | std::ios::out);

    const char *buffer = _buffer;

    m_file.write(buffer, _len);
    m_file.close();
    load();
}

void GFiles::File::append(char *_buffer, int _len)
{
    load();
    // char *leftoverData = this->read();

    // if (leftoverData != 0)
    // {
    //     this->write(leftoverData + _buffer, m_size + _len);
    // }
    // else
    // {
    //     this->write(_buffer, m_size);
    // }
    m_file.open(m_filePath.path, std::ios::binary | std::ios::out | std::ios::app);

    const char *buffer = _buffer;

    m_file.write(buffer, _len);
    m_file.close();
    load();
}

GFiles::File::~File()
{
    m_file.close();
    delete[] m_buffer;
}
