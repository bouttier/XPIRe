cmake_minimum_required(VERSION 2.6.0)

add_subdirectory("prng")

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(..)

add_library(pir_crypto STATIC
    AbstractPublicParameters.cpp
    HomomorphicCrypto.cpp
    HomomorphicCryptoFactory.cpp
    LatticesBasedCryptosystem.cpp
    NFLLWE.cpp
    NFLLWEPublicParameters.cpp
    NFLParams.cpp
    NFLlib.cpp
    NoCryptography.cpp
    NoCryptographyPublicParameters.cpp
    PaillierAdapter.cpp
    PaillierKeys.cpp
    PaillierPrivateParameters.cpp
    PaillierPublicParameters.cpp)

target_link_libraries(pir_crypto pir_crypto_prng)
