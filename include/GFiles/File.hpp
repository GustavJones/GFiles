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
        int m_size;
        char *m_buffer;
        std::string m_bufferStr;
        bool m_bufferCreate;
        bool m_isBinary;

        void load();

    public:
        File(Path _filePath, bool _isBinary = false);
        bool exists();
        void create();
        void remove();
        int size();
        char *read();
        void write(char *_buffer, int _len);
        void append(char *_buffer, int _len);
        ~File();
    };
} // namespace GFiles