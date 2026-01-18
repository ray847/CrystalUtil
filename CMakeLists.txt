cmake_minimum_required(VERSION 3.15)

# Project Options
project(CrystalUtil CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# External Libraries
#add_subdirectory(lib/json)
if (NOT TARGET spdlog)
  add_subdirectory(lib/spdlog)
endif()

# Internal Library
add_library(CrystalUtil)
target_sources(CrystalUtil
  PRIVATE
    src/util.cpp
    src/log.cpp
)
target_include_directories(CrystalUtil
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(CrystalUtil
  PRIVATE
    spdlog::spdlog
)

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  message(STATUS "Building CrystalUtil Standalone (with tests/main)")
  # Main
  add_executable(main main.cpp)
  target_include_directories(main
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
  target_link_libraries(main
  PRIVATE
    CrystalUtil
  )

  # Testing
  add_subdirectory(test)
endif()

