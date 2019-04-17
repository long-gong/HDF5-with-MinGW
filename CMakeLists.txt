cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(foo)
set(CMAKE_CXX_STANDARD 11)

# tell cmake where to locate the cmake module for HDF5
#set(HDF5_DIR C:\\Users\\saber\\HDF5\\1.10.5\\cmake\\hdf5)
# copied from HighFive, not sure why need use QUIET
#find_package(HDF5 REQUIRED)
# for debug purpose
#message(STATUS "\tHDF5 include dir: ${HDF5_INCLUDE_DIR}\n\tHDF5 libraries: ${HDF5_LIBRARIES}")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd-party C:\\Users\\saber\\HDF5\\1.10.5\\include)
#include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party
#        ${HDF5_INCLUDE_DIR})
link_directories(SYSTEM C:\\Users\\saber\\HDF5\\1.10.5\\lib)
add_executable(hdf5_demo example.cpp)
#target_link_libraries(
#        hdf5_demo
#        ${HDF5_C_LIBRARIES}
#)
target_link_libraries(
        hdf5_demo
        libhdf5_cpp
        libhdf5)