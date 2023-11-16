#include "Path.hpp"
#include <stdexcept>

GFiles::Path::Path(std::string _path, char _delimiter)
    : path(_path), m_delimiter(_delimiter)
{
    short lastDelimiterPos;

    // Check for empty directories
    if (path == "")
    {
        throw std::out_of_range("Path object is empty");
    }

    // Check for directories with a starting space
    if (path.find(m_delimiter + ' ') != -1)
    {
        throw std::invalid_argument("Path contains directory that starts with a space");
    }

    // Check for double usage of delimiter
    if (path.find(m_delimiter + m_delimiter) != -1)
    {
        throw std::invalid_argument("Path contains an empty directory");
    }

    // Last delimiter
    lastDelimiterPos = path.find_last_of(m_delimiter);

    // Check for . and test for file
    for (int i = lastDelimiterPos; i < path.length(); i++)
    {
        if (path[i] == '.')
        {
            m_isFile == true;
        }
    }
}

bool GFiles::Path::isfile()
{
    return m_isFile;
}

GFiles::Path::~Path()
{
}
