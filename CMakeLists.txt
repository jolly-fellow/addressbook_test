cmake_minimum_required(VERSION 3.16)
project(addressbook)

set(CMAKE_CXX_STANDARD 17)

# add_subdirectory(test)

add_library(addressbook addressbook.cpp addressbook.hpp)

# Make sure the compiler can find include files for our library
target_include_directories (addressbook PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_exe test/main.cpp)

# Link the executable to the library. Since the library has
# public include directories we will use those link directories when building
# the demo
target_link_libraries (test_exe LINK_PUBLIC addressbook)