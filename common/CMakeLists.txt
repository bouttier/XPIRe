cmake_minimum_required(VERSION 2.6.0)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory("crypto")
add_subdirectory("optim")

add_library(pir SHARED ToolsBox.cpp)

target_link_libraries(pir pir_crypto pir_optim)
