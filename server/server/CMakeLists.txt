cmake_minimum_required(VERSION 2.6.0)

set(CMAKE_EXE_LINKER_FLAGS "-fopenmp")

include_directories(..)
include_directories(../../common)

add_executable(pir_server DBDirectoryProcessor.cpp DBGenerator.cpp PIRServer.cpp PIRSession.cpp ServerService.cpp main.cpp)

target_link_libraries(pir_server pir pir_server_optim pir_server_pir ${Boost_LIBRARIES} pthread gmp pir_crypto_prng)
