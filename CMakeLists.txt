cmake_minimum_required(VERSION 2.6.0)

project(XPIRe)

find_package(Boost 1.55.0 REQUIRED
    COMPONENTS atomic chrono date_time exception program_options regex system thread)
#find_package(mpfr 3.1.2 REQUIRED)
#find_package(GMP 6 REQUIRED)


add_subdirectory("common")
add_subdirectory("server")
add_subdirectory("client")
