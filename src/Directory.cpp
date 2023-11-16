#include "Directory.hpp"
#include <iostream>

GFiles::Directory::Directory(const Path &_directoryPath)
    : m_directoryPath(&_directoryPath)
{
}

#ifdef unix
#include <sys/stat.h>

bool GFiles::Directory::exists()
{
    struct stat st;
    if (stat(m_directoryPath->path.c_str(), &st) == 0)
    {
        if (std.st_mode & S_IFDIR != 0)
            return true;
    }
    else
    {
        return false;
    }
}

void GFiles::Directory::createDirectory()
{
    mkdir(m_directoryPath->path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

void GFiles::Directory::removeDirectory()
{
    remove(m_directoryPath->path.c_str());
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
