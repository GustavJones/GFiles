# GFiles

GFiles is a library for C++ 11 to manipulate files and directories. 

The library works by using `std::fstream` to open and close files and various
different OS specific libraries to manipulate directories.

## Features
- A class for containing paths ( `GFiles::Path` ) : [Path Header](include/GFiles/Path.hpp)
- A class for manipulating directories ( `GFiles::Directory` ) : [Directory Header](include/GFiles/Directory.hpp)
- A class for manipulating files ( `GFiles::File` ) : [File Header](include/GFiles/File.hpp)

## Path
```c++
    // GFiles::Path::Path(std::string _path, char _delimiter = '/');

    // Example Directories
    GFiles::Path p1("/usr/local/games");
    GFiles::Path p2("C:\\Windows\\System32", '\\');

    // Example Files
    GFiles::Path p3("/usr/local/games/example.txt");
    GFiles::Path p4("C:\\Windows\\System32\\example.txt", '\\');

    // .isfile();
    std::cout << p3.isfile() << '\n'; // Output 1 for true
    std::cout << p1.isfile() << '\n'; // Output 0 for false

    // .path
    std::cout << p3.path << '\n'; // Output /usr/local/bin/example.txt
    std::cout << p1.path << '\n'; // Output /usr/local/bin
```

More examples at [test1](tests/test1/main.cpp)

## Directory
```c++
    // GFiles::Directory::Directory(const GFiles::Path &_directoryPath)

    // Example
    GFiles::Directory d1(p1); // p1 declared above ^

    d1.createDirectory();
    d1.removeDirectory();

    std::cout << d1.exists() << '\n'; // Outputs 1 if directory exists (true)
```

More examples at [test2](tests/test2/main.cpp)

## File
```c++
    // GFiles::File::File(Path _filePath)

    // Example
    GFiles::File f1(GFiles::Path("C:\\CXXProjects\\GFiles\\tests\\test3\\test.json", '\\'));
    f1.create();
    f1.remove();

    std::cout << f1.size() << '\n';
    std::cout << f1.exists() << '\n';

    std::cout << f1.read() << "\n"; // Outputs file content
    f1.write("Write\n"); // Writes to the file
    f1.append("Append\n"); // Append to the end of the file
```

More examples at [test3](tests/test3/main.cpp)