cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
project(HexagonEngine)

if(MSVC)
	set(CMAKE_CXX_FLAGS "/W4")
else()
	set(CMAKE_CXX_FLAGS "-Wall")
endif()

# SDL 2
set(SDL2_DIR Dependencies/SDL2)
find_package(SDL2 REQUIRED PATH Dependencies/SDL2)

set(SRC_FILES
	"Example/Basic.cpp"
)

# begin spdlog
set(SPDLOG_VERSION "1.4.2" CACHE STRING "spdlog version")
FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG        "v${SPDLOG_VERSION}"
)

FetchContent_GetProperties(spdlog)
if(NOT spdlog_POPULATED)
  FetchContent_Populate(spdlog)
  add_subdirectory(${spdlog_SOURCE_DIR} ${spdlog_BINARY_DIR})
endif()
# end spdlog

add_subdirectory("Source")

add_executable(HexagonEngineApp
	${SRC_FILES}
)

target_include_directories(HexagonEngineApp PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(
	HexagonEngineApp
	HexagonEngineCore
	${SDL2_LIBRARIES}
	${CMAKE_DL_LIBS}
	spdlog::spdlog
)

if(NOT WIN32)
add_subdirectory("Test")
endif()
