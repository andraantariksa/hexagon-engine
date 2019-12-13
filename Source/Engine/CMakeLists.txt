file(GLOB_RECURSE ENGINE_SRC_FILES
	"*.c"
	"*.cpp"
	"*.cxx"
	"*.h"
	"*.hpp")

add_library(HexagonEngineCore STATIC ${ENGINE_SRC_FILES})

target_include_directories(
	HexagonEngineCore
	PRIVATE
	${SDL2_INCLUDE_DIRS})
