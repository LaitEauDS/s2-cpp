cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

project(TD6)

if (MSVC)
    add_compile_options(/W3)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -pedantic-errors)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "./src/*.cpp")

add_executable(TD6 ${SRC_FILES})

target_include_directories(TD6 PUBLIC "src/")

