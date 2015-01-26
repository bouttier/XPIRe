cmake_minimum_required(VERSION 2.6.0)

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(..)
include_directories(../../common)

add_executable(pir_client_test main.cpp)

target_link_libraries(pir_client_test pir pir_client_optim pir_client_events pir_client_pir)
