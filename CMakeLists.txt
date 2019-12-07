cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17) # do we really need C++17 standard?
project(HexagonEngine)

set(SDL2_DIR Dependencies/SDL2)
find_package(SDL2 REQUIRED PATH Dependencies/SDL2)

set(SRC_FILES
	HexagonEngine.cpp)

set(HEADER_FILES
	HexagonEngine.h)

add_subdirectory("Source")

add_executable(HexagonEngineApp ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(HexagonEngineApp HexagonEngineCore ${SDL2_LIBRARIES})
