cmake_minimum_required(VERSION 2.6.0)

include_directories(..)
include_directories(../../common)

add_library(pir_client_pir STATIC PIRQueryGenerator.cpp PIRReplyExtraction.cpp PIRReplyWriter.cpp)
