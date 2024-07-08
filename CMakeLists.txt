cmake_minimum_required(VERSION 3.8)

project(CppProjectTemplate
  VERSION 1.0.0
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_EXTENSIONS OFF)


enable_testing()

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

include(CPM)
include(Warnings)

CPMAddPackage("gh:google/googletest#v1.14.0")

add_subdirectory(src)
add_subdirectory(tests)