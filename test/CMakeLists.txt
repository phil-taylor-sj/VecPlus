cmake_minimum_required(VERSION 3.10)

enable_testing()

set(TEST_TARGET VecPlus_Tests)

set(TEST_SRCS
    pch.cpp
    pch.h
    Vec2i_Test.cpp
    Vec2d_Test.cpp
    Vec2f_Test.cpp
    Vec3i_Test.cpp
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt On CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_TARGET} ${TEST_SRCS})
target_link_libraries(${TEST_TARGET}
    gtest gtest_main gmock_main VecPlus
)

target_include_directories(${TEST_TARGET} PUBLIC ${PUBLIC_INCLUDE_DIR})

set_target_properties(${TEST_TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BIN_DIR}
)

include(GoogleTest)
gtest_discover_tests(${TEST_TARGET})