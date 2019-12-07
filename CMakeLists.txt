cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
project(HexagonEngine)

set(SDL2_DIR Dependencies/SDL2)
find_package(SDL2 REQUIRED PATH Dependencies/SDL2)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(HexagonEngine "Hexagon Engine")

target_link_libraries(HexagonEngine ${SDL2_LIBRARIES})