include_directories(inc)

add_library(circle_lib src/circle.cpp)
add_library(simpleCalc_lib src/simpleCalc.cpp)
add_library(librarySystem_lib src/librarySystem.cpp)
add_library(stdViews_lib src/stdViews.cpp)
add_library(sequenceContainers_lib src/sequenceContainers.cpp)
add_library(associativeContainers_lib src/associativeContainers.cpp)
add_library(specialContainers_lib src/specialContainers.cpp)
add_library(oop_lib src/oop.cpp)

add_subdirectory(test)