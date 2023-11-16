add_executable(test1 main.cpp)
target_include_directories(test1 PRIVATE ../../include)
target_link_libraries(test1 PRIVATE FileManage)