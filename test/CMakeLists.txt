enable_testing()

file(GLOB APP_SOURCES
    "../**/*.h"
    "../**/*.cpp"
)

file(GLOB TEST_SOURCES
    "*.h"
    "*.cpp"
)

add_executable(
  basic_test
  ${APP_SOURCES}
  ${TEST_SOURCES}
)

target_link_libraries(
    basic_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(basic_test)
