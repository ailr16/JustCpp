cmake_minimum_required(VERSION 3.14)
project(ExercisesUnitTesting)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##################################
# Download and install GoogleTest

include(FetchContent)
FetchContent_Declare(googleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(googleTest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

enable_testing()

################
# Define a test
add_executable(firstTest TEST__circle.cpp)

target_link_libraries(firstTest
    PRIVATE
        GTest::GTest
        gmock
        circle_library
)

target_include_directories(circle_test PRIVATE ../inc)

#Simple Calculator tests

add_executable(simpleCalc_test TEST__simpleCalc.cpp)

target_link_libraries(simpleCalc_test
    PRIVATE
        GTest::GTest
        gmock
        simpleCalc_lib
)

target_include_directories(simpleCalc_test PRIVATE ../inc)


add_test(NAME    test
         COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/circle_test
                 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/simpleCalc_test
)