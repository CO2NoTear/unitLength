find_package(GTest CONFIG REQUIRED)

add_executable(runUnitTests
  suffixTransformTest.cpp
  lengthClassTest.cpp
  convertToMetersTest.cpp
  ${PROJECT_SOURCE_DIR}/src/length.cpp
  ${PROJECT_SOURCE_DIR}/src/lengthUtils.cpp)

target_link_libraries(runUnitTests GTest::gtest
  GTest::gtest_main GTest::gmock GTest::gmock_main)
target_include_directories(runUnitTests PRIVATE ${PROJECT_SOURCE_DIR}/include/)

include(GoogleTest)
gtest_discover_tests(runUnitTests)

add_test(NAME runUnitTests COMMAND runUnitTests)
