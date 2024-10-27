cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ccodebase LANGUAGES C VERSION 0.1.0)

file(GLOB_RECURSE SRC_FILES src/*.c)

include_directories(include)

if (MSVC)
   add_compile_options(/W4)
else()
   add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_library(ccodebase STATIC ${SRC_FILES})

add_executable(run main.c)

target_link_libraries(run ccodebase)

