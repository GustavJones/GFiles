add_executable(test2 main.cpp)
target_include_directories(test2 PRIVATE ../../include)
target_link_libraries(test2 PRIVATE FileManage)