cmake_minimum_required(VERSION 2.6.0)

set (CMAKE_EXE_LINKER_FLAGS "-fopenmp")

include_directories(..)
include_directories(../../common)

add_executable(pir_client DESC.cpp PIRClient.cpp PIRClientLog.cpp PIRController.cpp PIRView.cpp PIRViewCLI.cpp main.cpp)

target_link_libraries(pir_client pir pir_client_events pir_client_optim
pir_client_pir pthread ${GMP_LIBRARIES} ${MPFR_LIBRARIES} ${Boost_LIBRARIES})
