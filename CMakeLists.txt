cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
project(HexagonEngine)

if(NOT MSVC)
	# Dumbass Microsoft for /W4. Why are they treating warning as error?
	# https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2220?view=vs-2019
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
#	SDL2_mixer
)

add_subdirectory("Test")