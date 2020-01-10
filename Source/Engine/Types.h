#pragma once

#include "../Config.h"

#ifdef HX_COMPILER_MSVC
#define HX_NOVTABLE __declspec(novtable)
#else
#define HX_NOVTABLE
#endif

typedef char int8;
typedef short int16;
typedef int int32;
typedef long long int64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
