cmake_minimum_required(VERSION 3.20)
project(DTL)

# TODO: bump to 23 once clang supports it
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


add_library(dtl STATIC src/crypto/md5.cpp src/panic.cpp)
set_target_properties(dtl PROPERTIES CXX_CLANG_TIDY "clang-tidy;--use-color")
target_link_libraries(dtl PRIVATE ${CONAN_LIBS})
target_include_directories(dtl PRIVATE include)

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if (${FORCE_COLORED_OUTPUT})
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
       add_compile_options(-fdiagnostics-color=always)
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_compile_options (-fcolor-diagnostics)
    endif ()
endif ()

add_subdirectory("test")
add_subdirectory("docs")