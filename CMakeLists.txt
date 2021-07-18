cmake_minimum_required(VERSION 3.14)
project(DTL)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(dtl STATIC src/crypto/md5.cpp)
target_link_libraries(dtl PRIVATE STATIC ${CONAN_LIBS})
target_include_directories(dtl PRIVATE include)

add_subdirectory("test")
add_subdirectory("docs")