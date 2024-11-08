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

set(REQ_LIBS "")
include(CheckLibraryExists)

# check if math library is available for needed functions
check_library_exists(m sqrt "" LIBM_SQRT) 
check_library_exists(m sin "" LIBM_SIN)
check_library_exists(m cos "" LIBM_COS)
check_library_exists(m fmax "" LIBM_FMAX)
check_library_exists(m fmin "" LIBM_FMIN)
check_library_exists(m fabs "" LIBM_FABS)
check_library_exists(m floor "" LIBM_FLOOR)
check_library_exists(m ceil "" LIBM_CEIL)
check_library_exists(m round "" LIBM_ROUND)

if (LIBM_SQRT OR LIBM_SIN OR LIBM_COS OR LIBM_FMAX OR LIBM_FMIN OR LIBM_FABS OR LIBM_FLOOR OR LIBM_CEIL OR LIBM_ROUND)
   list(APPEND REQ_LIBS m)
endif()

message(STATUS "Required libraries: ${REQUIRED_LIBRARIES}")

add_library(ccodebase STATIC ${SRC_FILES})

target_link_libraries(ccodebase ${REQ_LIBS})
