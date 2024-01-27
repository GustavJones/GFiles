file(GLOB GFiles_SRC "*.cpp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(BUILD_SHARED_LIBS)
  add_library(GFiles SHARED ${GFiles_SRC})
else()
  add_library(GFiles STATIC ${GFiles_SRC})
endif()

target_include_directories(GFiles PRIVATE ../include/GFiles)
