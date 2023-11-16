#pragma once
#include "Path.hpp"

namespace GFiles
{
    class Directory
    {
    private:
        const Path *m_directoryPath;

    public:
        Directory(const Path &_directoryPath);

        bool exists();

        void createDirectory();
        void removeDirectory();

        ~Directory();
    };
} // namespace GFiles
