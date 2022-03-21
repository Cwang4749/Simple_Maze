cmake_minimum_required(VERSION 3.16)

project(Free)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DYAM_WINDOWS)
elseif(APPLE)
	add_definitions(-DYAM_MACOS)
elseif(UNIX)
	add_definitions(-DYAM_LINUX)
endif()

add_subdirectory(Free)
add_subdirectory(Yam)
add_subdirectory(glfw)