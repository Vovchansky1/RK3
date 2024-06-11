cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(plus)

option(BUILD_MAIN "Build app" OFF)
option(BUILD_TESTS "Build tests" OFF)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(plus STATIC ${CMAKE_CURRENT_SOURCE_DIR}/plus_l.cpp)

if (BUILD_MAIN)
    add_executable(plus_main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    target_link_libraries(plus_main plus)
    install(TARGETS plus_main RUNTIME DESTINATION plus)
endif()

if (BUILD_TESTS)
    #add_subdirectory(third-party/gtest)
    enable_testing()
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    file(GLOB TEST_SOURCES test.cpp)
    add_executable(check ${TEST_SOURCES})
    target_link_libraries(check gtest_main gtest plus)
    add_test(NAME check COMMAND check)
endif()
