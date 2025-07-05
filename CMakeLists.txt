cmake_minimum_required(VERSION 3.10)

project(VecPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message(STATUS "This project has a top-level one called [${CMAKE_PROJECT_NAME}]")
else()
    message(STATUS "This project is a top-level one")
endif()

#option(VECPLUS_BUILD_TESTS "Build all of VecPlus's own tests." OFF)

#set(PUBLIC_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
#set(PUBLIC_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}/Vec2Decimal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}/Vec2Int.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}/Vec3Decimal.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}/Vec3Int.cpp 
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/VecPlus>
)

include(GNUInstallDirs)
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

set(public_headers 
    include/VecPlus/Vec2.h 
    include/VecPlus/Vec2Decimal.h 
    include/VecPlus/Vec2Int.h
    include/VecPlus/Vec3.h
    include/VecPlus/Vec3Int.h
    include/VecPlus/vec3Decimal.h
    )
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")

install(DIRECTORY include/ DESTINATION include)


#set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")
set_target_properties(${PROJECT_NAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/$<CONFIG>"
    LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib/$<CONFIG>"
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin/$<CONFIG>"
)


install(TARGETS ${PROJECT_NAME} 
    EXPORT "${PROJECT_NAME}Targets"
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

#target_include_directories(vecplus PUBLIC
#    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
#    $<INSTALL_INTERFACE:include/VecPlus/Vec2>
#)

install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE VecPlus::
    DESTINATION lib/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    DESTINATION lib/cmake/${PROJECT_NAME}
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(PROJECT_IS_TOP_LEVEL ON)
else()
    set(PROJECT_IS_TOP_LEVEL OFF)
endif()

if(PROJECT_IS_TOP_LEVEL)
    enable_testing()
    add_subdirectory(test)
endif()
