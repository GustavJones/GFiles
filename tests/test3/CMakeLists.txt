add_executable(test3 main.cpp)
target_include_directories(test3 PRIVATE ../../include)
target_link_libraries(test3 PRIVATE FileManage)