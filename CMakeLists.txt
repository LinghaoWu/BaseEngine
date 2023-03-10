cmake_minimum_required(VERSION 3.25.1)

project(openGLGame VERSION 0.01)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(HEADER_PATH src/Engine/include)
list(APPEND HEADER_PATH src/Core/include)
include(CMakeModule/FindModule.cmake)
include_directories(${HEADER_PATH})

aux_source_directory(src/Engine ALL_SRC)
aux_source_directory(src/Core ALL_SRC)

add_executable(${PROJECT_NAME} ${ALL_SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE -mwindows glfw3dll freetypedll)