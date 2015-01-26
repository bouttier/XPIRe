cmake_minimum_required(VERSION 2.6.0)

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(..)
include_directories(../../common)

add_library(pir_client_optim STATIC PIROptimizer.cpp)
