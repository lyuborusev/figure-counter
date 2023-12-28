cmake_minimum_required(VERSION 3.0.0)
project(figure-counter VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB APP_SOURCES
    "*.h"
    "*.cpp"
    "figure-counter/*.h"
    "figure-counter/*.cpp"
    "figure-counter/travere/*.h"
    "figure-counter/traverse/*.cpp"
    "test/*.h"
    "test/*.cpp"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
  basic_test
  ${APP_SOURCES}
)

target_link_libraries(
    basic_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(basic_test)