cmake_minimum_required(VERSION 3.23)
project(
  example
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In source builds are not allowed\n")
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  include(CTest)

  find_package(Doxygen)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs.\n")
  endif()
endif()

add_subdirectory(src)

add_subdirectory(lib)

# target_link_libraries(example lib)

enable_testing()

if(BUILD_TESTING)
  add_subdirectory(test)
endif()

if(MSVC)
  foreach(target ${TARGET_LIST})
    target_compile_options(${target} PUBLIC /W4 /permessive)
  endforeach()
else()
  foreach(target ${TARGET_LIST})
    target_compile_options(${target} PUBLIC -w -Wall -Wextra -Wpedantic
                                            -Weverything)
  endforeach()
endif()
