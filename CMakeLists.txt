cmake_minimum_required(VERSION 3.14)
project(MaxValueProject VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable testing
enable_testing()

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create header-only library interface
add_library(max_value INTERFACE)
target_include_directories(max_value INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Create test executable
add_executable(max_value_test max_value_test.cpp)
target_link_libraries(max_value_test
  PRIVATE
    max_value
    gtest_main
)

# Add test to CTest
include(GoogleTest)
gtest_discover_tests(max_value_test)

# Optional: Add compiler warnings
if(MSVC)
  target_compile_options(max_value_test PRIVATE /W4)
else()
  target_compile_options(max_value_test PRIVATE -Wall -Wextra -Wpedantic)
endif()
