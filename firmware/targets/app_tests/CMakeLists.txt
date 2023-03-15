cmake_minimum_required(VERSION 3.25.0)
project(AppTests)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
find_package(GTest REQUIRED)

target_sources(app
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(app
    PRIVATE
        $<$<BOOL:${CONFIG_FOO_COMPONENT_TESTS}>:Components::FooTests>
        GTest::gtest
        GTest::gmock
)
