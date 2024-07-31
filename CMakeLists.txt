cmake_minimum_required(VERSION 3.10)

project(ocltest)
set(CXX_STANDARD_REQUIRED 17)
set(EXPORT_COMPILE_COMMANDS ON)

include_directories(src)
include_directories(src/3rdparty)

if(ANDROID)
    add_subdirectory(src/3rdparty/libopencl-stub)

    add_library(ocltest SHARED
        src/main.cpp
    )

    target_include_directories(ocltest PRIVATE
        src/3rdparty/libopencl-stub/include
    )

    target_link_libraries(ocltest PRIVATE
        OpenCL
    )
endif()
