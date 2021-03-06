cmake_minimum_required(VERSION 3.4)
project(Blatt1-Tests)

# we require that nastlib has been built first
# otherwise we cannot do any tests
if (NOT TARGET "fieldlib")
  find_package(blatt1 REQUIRED)
endif()


#This is a downloader for GoogleTest
#downloads the project at configure time
enable_testing()
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(AddGoogleTest)

# list any further test sources here
set(TESTSOURCES
    blatt1_tests.cpp
)

# this is our executable for the unit tests
add_executable(runUnitTests ${TESTSOURCES})
## links exectuable with nastlib and google test
target_link_libraries(runUnitTests PRIVATE fieldlib gtest_main)

# add_gtest is just a macro that adds gtest, gmock, and gtest_main, and then runs add_test to create a test with the same name:
# target_link_libraries(runUnitTests gtest gmock gtest_main)
# add_test(runUnitTests runUnitTests)
add_gtest(runUnitTests)
