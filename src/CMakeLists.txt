cmake_minimum_required(VERSION 2.8.9)

# Maybe stop from CMAKEing in the wrong place
if (CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "Source and build directories cannot be the same. Go use the /build directory.")
endif()
add_executable(
  embind
  main.cpp
)

target_include_directories(embind PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../src")
target_link_libraries(embind geometry-central)
set_target_properties(embind PROPERTIES LINK_FLAGS "-s DEMANGLE_SUPPORT=1 -s ALLOW_MEMORY_GROWTH=1 --bind")
