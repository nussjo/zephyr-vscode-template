cmake_minimum_required(VERSION 3.25.0)
project(Foo)

add_library(${PROJECT_NAME})
add_library(Components::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/foo/hello.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/hello.cpp
        )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        zephyr_interface
)

if(${CONFIG_FOO_COMPONENT_TESTS})
    add_subdirectory(tests)
    # enable tests to see detail headers
    target_include_directories(${PROJECT_NAME}Tests
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
endif()
