cmake_minimum_required(VERSION 3.18)

include(kvasir/cmake/kvasir.cmake)

project("blinky" VERSION 0.0.1)

include(kvasir/cmake/util.cmake)

#add_subdirectory(aglio)

add_executable(debug src/main.cpp)
target_configure_kvasir(debug OPTIMIZATION_STRATEGY size USE_LOG)
target_include_directories(debug PUBLIC src)
#target_link_libraries(debug aglio)

add_executable(blinky src/main.cpp)
target_configure_kvasir(blinky OPTIMIZATION_STRATEGY size)
#target_link_libraries(blinky aglio)
