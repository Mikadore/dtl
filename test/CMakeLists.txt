include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tests
  forward.cpp
  tuple.cpp
  typeops.cpp
  integral.cpp
  crypto/md5.cpp
)

target_link_libraries(
  tests
  gtest_main
  dtl
)

target_include_directories(
  tests
  PRIVATE
  ../include
)

include(GoogleTest)
gtest_discover_tests(tests)

# Tests whole programs behaving correctly,
# mostly done for utilities which cannot
# be tested with gtest. Requires Python
add_subdirectory(programs)