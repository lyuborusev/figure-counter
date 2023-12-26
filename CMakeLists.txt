cmake_minimum_required(VERSION 3.0.0)
project(figure-counter VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB APP_SOURCES
    "*.h"
    "*.cpp"
)

add_executable(
    figure-counter 
    ${APP_SOURCES}
    ${TEST_SOURCES}
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

add_subdirectory(test)