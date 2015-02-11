cmake_minimum_required(VERSION 2.6.0)

include_directories(..)
include_directories(../../common)

add_library(pir_server_optim STATIC PIROptimizer.cpp)
