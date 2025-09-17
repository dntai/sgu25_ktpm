cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

# Our library
add_library(mylib src/lib/math_lib.cpp src/lib/algebra.cpp src/lib/logger.cpp)
target_include_directories(mylib PUBLIC lib)

# Our executables
add_executable(app src/app.cpp)

add_executable(max src/max_app.cpp)
target_link_libraries(max mylib)

add_executable(algebra src/algebra_app.cpp)
target_link_libraries(algebra mylib)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  max_test
  tests/max_test.cpp
)
target_link_libraries(
  max_test
  gtest_main
  mylib
)

target_include_directories(max_test PRIVATE src/lib)
target_include_directories(max_test PRIVATE ${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(max_test)

add_executable(
  algebra_test
  tests/algebra_test.cpp
)
target_link_libraries(
  algebra_test
  gtest_main
  gmock
  mylib
)
target_include_directories(algebra_test PRIVATE src/lib)
target_include_directories(algebra_test PRIVATE ${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

gtest_discover_tests(algebra_test)