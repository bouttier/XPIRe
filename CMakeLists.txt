cmake_minimum_required(VERSION 2.6.0)

project(XPIRe)

enable_language(CXX ASM)

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(Boost 1.55.0 REQUIRED
    COMPONENTS atomic chrono date_time exception program_options regex system thread)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
find_package(GMP 6 REQUIRED)
find_package(MPFR 3.1.2 REQUIRED)


add_subdirectory("common")
add_subdirectory("server")
add_subdirectory("client")
