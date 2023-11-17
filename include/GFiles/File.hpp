#pragma once
#include "Path.hpp"
#include <fstream>

namespace GFiles
{
    class File
    {
    private:
        Path m_filePath;
        std::fstream m_file;
        bool m_exists;
        short m_size;
        char *m_buffer;
        bool m_read;

        void load();
        void loadData();

    public:
        File(Path _filePath);
        bool exists();
        void create();
        void remove();
        short size();
        char *read();
        void write(std::string _buffer);
        void append(std::string _buffer);
        ~File();
    };
} // namespace GFiles