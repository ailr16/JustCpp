include_directories(inc)

add_library(circle_lib src/circle.cpp)
add_library(simpleCalc_lib src/simpleCalc.cpp)
add_library(librarySystem_lib src/librarySystem.cpp)

add_subdirectory(test)