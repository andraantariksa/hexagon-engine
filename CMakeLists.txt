cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17) # do we really need C++17 standard?
project(HexagonEngine)

include(FetchContent)

# Google Test
set(GTEST_VERSION 1.10.0 CACHE STRING "Google test version")
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        release-${GTEST_VERSION}
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# enable_testing()

# SDL 2
set(SDL2_DIR Dependencies/SDL2)
find_package(SDL2 REQUIRED PATH Dependencies/SDL2)

set(SRC_FILES
	HexagonEngine.cpp)

set(HEADER_FILES
	HexagonEngine.h)

add_subdirectory("Source")

add_executable(HexagonEngineApp ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(HexagonEngineApp HexagonEngineCore ${SDL2_LIBRARIES})
