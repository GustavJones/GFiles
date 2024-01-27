file(GLOB FileManage_SRC "*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(BUILD_SHARED_LIBS)
  add_library(FileManage SHARED ${FileManage_SRC})
else()
  add_library(FileManage STATIC ${FileManage_SRC})
endif()

target_include_directories(FileManage PRIVATE ../include/GFiles)
