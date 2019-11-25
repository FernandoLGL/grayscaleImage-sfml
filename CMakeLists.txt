cmake_minimum_required(VERSION 3.5)

project(grayscale LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#can't do in-source builds
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

set(SOURCE
        # add other files here
        main.cpp
        )

add_executable(grayscale ${SOURCE})

#target_include_directories(grayscale PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(grayscale PRIVATE sfml-graphics)
