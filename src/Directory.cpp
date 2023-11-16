#include "Directory.hpp"
#include <iostream>

GFiles::Directory::Directory(const Path &_directoryPath)
    : m_directoryPath(&_directoryPath)
{
}

bool GFiles::Directory::exists()
{
    return false;
}

#ifdef unix
#include <sys/stat.h>

void GFiles::Directory::createDirectory()
{
    // mkdir(m_directoryPath->path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    mkdir(m_directoryPath->path.c_str());
}

void GFiles::Directory::removeDirectory()
{
}

#elif _WIN32
#include <direct.h>

void GFiles::Directory::createDirectory()
{
    _mkdir(m_directoryPath->path.c_str());
}

void GFiles::Directory::removeDirectory()
{
    _rmdir(m_directoryPath->path.c_str());
}

#endif

GFiles::Directory::~Directory()
{
}
