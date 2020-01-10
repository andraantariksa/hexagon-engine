#pragma once

#define HX_PLATFORM_SDL2 1 // We only define SDL2 platform for now

// Compiler vibe check
#if defined(_MSC_VER)
#	define HX_COMPILER_MSVC 1
#	define HX_COMPILER_VER _MSC_VER
#elif defined(__clang__)
#	define HX_COMPILER_CLANG 1
#	define HX_COMPILER_VER __clang_version__
#elif defined(__GNUC__)
#	define HX_COMPILER_GNUC 1
#	define HX_COMPILER_VER __GNUC__
#endif
