file(GLOB ENGINE_SRC_FILES
	"*.cpp"
	"Window/*.cpp"
	"Window/Native/*.cpp"
	"Window/Native/SDL2/*.cpp")

file(GLOB ENGINE_HEADER_FILES
	"*.h"
	"Window/*.h"
	"Window/Native/*.h"
	"Window/Native/SDL2/*.h")

add_library(HexagonEngineCore STATIC ${ENGINE_SRC_FILES} ${ENGINE_HEADER_FILES})

target_include_directories(
	HexagonEngineCore
	PRIVATE
	${SDL2_INCLUDE_DIRS})
