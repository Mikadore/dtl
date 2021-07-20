function(python_test cppfile pythonfile)
    string(REGEX REPLACE "\.cpp" ".test" target ${cppfile})
    add_executable(${target} ${cppfile})
    target_include_directories(${target} PRIVATE ../../include)
    target_link_libraries(${target} PRIVATE dtl)
    configure_file(${pythonfile} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${pythonfile} COPYONLY)
endfunction()

python_test(panic.cpp panic.py)

configure_file(_test_programs.py ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test_programs.py COPYONLY)