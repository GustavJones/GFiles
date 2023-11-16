#pragma once
#include <string>

namespace GFiles
{
    class Path
    {
    private:
        char m_delimiter;
        bool m_isFile;

    public:
        std::string path;

        Path(std::string _path, char _delimiter = '/');

        bool isfile();

        ~Path();
    };
} // namespace GFiles
