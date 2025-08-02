cmake_minimum_required (VERSION 3.14)

project(unitLength VERSION 0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 23)
endif()

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(main ${SRC_LIST})
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include/)

enable_testing()
add_subdirectory(tests)
