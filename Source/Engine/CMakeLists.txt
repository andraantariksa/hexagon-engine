file(GLOB ENGINE_SRC_FILES
	"*.cpp"
	"Window/*.cpp"
	"Window/Native/*.cpp"
	"Window/Native/SDL2/*.cpp"
	"Renderer/Backend/*.cpp"
	"Renderer/Backend/GL/*.cpp")

file(GLOB ENGINE_HEADER_FILES
	"*.h"
	"Window/*.h"
	"Window/Native/*.h"
	"Window/Native/SDL2/*.h"
	"Renderer/Backend/*.h"
	"Renderer/Backend/GL/*.h")

add_library(HexagonEngineCore STATIC ${ENGINE_SRC_FILES} ${ENGINE_HEADER_FILES})

message(${SDL2_INCLUDE_DIRS})

target_include_directories(
	HexagonEngineCore
	PRIVATE
	${SDL2_INCLUDE_DIRS})
