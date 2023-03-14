cmake_minimum_required(VERSION 3.25.0)
project(FooTests)

add_library(${PROJECT_NAME} OBJECT)
add_library(Components::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

find_package(GTest REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Components::Foo
        GTest::gtest
        GTest::gmock
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/FooTests.cpp
)
