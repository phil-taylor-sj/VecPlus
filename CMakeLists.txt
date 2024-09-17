cmake_minimum_required(VERSION 3.10)

# Project name
project(VecPlus VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Message if it's a top-level project
if (NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "This project has a top-level one called [${CMAKE_PROJECT_NAME}]")
else()
    message(STATUS "This project is a top-level one")
endif()

# Define the library
add_library(${PROJECT_NAME} SHARED)

# Add sources
target_sources(${PROJECT_NAME} 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/VecPlus/Vec2Decimal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/VecPlus/Vec2Int.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/VecPlus/Vec3Decimal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/VecPlus/Vec3Int.cpp 
)

# Include directories for consumers (PUBLIC) and private use (PRIVATE)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/VecPlus>
)

# Set up public headers
set(public_headers 
    include/VecPlus/Vec2.h 
    include/VecPlus/Vec2Decimal.h 
    include/VecPlus/Vec2Int.h
    include/VecPlus/Vec3.h
    include/VecPlus/Vec3Int.h
    include/VecPlus/Vec3Decimal.h
)

# Specify public headers in the target properties
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")

# Include installation directories
include(GNUInstallDirs)

# Set installation prefix if not already set
if(DEFINED CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX is not set\n"
        "Default value: ${CMAKE_INSTALL_PREFIX}\n"
        "Will set it to ${CMAKE_SOURCE_DIR}/install"
    )
    set(CMAKE_INSTALL_PREFIX
        "${CMAKE_SOURCE_DIR}/install"
        CACHE PATH "Where the library will be installed to" FORCE
    )
else()
    message(
        STATUS
        "CMAKE_INSTALL_PREFIX was already set\n"
        "Current value: ${CMAKE_INSTALL_PREFIX}"
    )
endif()

# Install the library, headers, and targets
install(TARGETS ${PROJECT_NAME} 
    EXPORT ${PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/VecPlus
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install the export targets
install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE VecPlus::
    DESTINATION lib/cmake/${PROJECT_NAME}
)

# Create a Config file for consumers of the library
include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

# Install the config file
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)

# Optionally enable testing if this is the top-level project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(PROJECT_IS_TOP_LEVEL ON)
else()
    set(PROJECT_IS_TOP_LEVEL OFF)
endif()

if(PROJECT_IS_TOP_LEVEL)
    enable_testing()
    add_subdirectory(test)
endif()
