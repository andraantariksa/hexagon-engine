#pragma once

#ifndef HX_DEFINED_MATH_H
#error "Cannot use StdMath.h directly!"
#endif

#include <cmath>

#define HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(NAME, STDNAME)	\
	template<typename T>									\
	inline T NAME(T x)										\
	{ return STDNAME(static_cast<T>(x)); }					\
	template<typename T>									\
	inline Vec2<T> NAME(const Vec2<T>& v2)					\
	{ return Vec2<T>(										\
		STDNAME(static_cast<T>(v2.X)),						\
		STDNAME(static_cast<T>(v2.Y))); }					\
	template<typename T>									\
	inline Vec3<T> NAME(const Vec3<T>& v3)					\
	{ return Vec3<T>(										\
		STDNAME(static_cast<T>(v3.X)),						\
		STDNAME(static_cast<T>(v3.Y)),						\
		STDNAME(static_cast<T>(v3.Z))); }					\
	template<typename T>									\
	inline Vec4<T> NAME(const Vec4<T>& v4)					\
	{ return Vec4<T>(										\
		STDNAME(static_cast<T>(v4.X)),						\
		STDNAME(static_cast<T>(v4.Y)),						\
		STDNAME(static_cast<T>(v4.Z)),						\
		STDNAME(static_cast<T>(v4.W))); }

#define HX_STDMATH_MAKE_FLOAT_FUNCTION1(NAME, STDNAME)		\
	inline float NAME(float x)								\
	{ return STDNAME(x); }									\
	inline Vec2<float> NAME(const Vec2<float>& v2)			\
	{ return Vec2<float>(STDNAME(v2.X), STDNAME(v2.Y)); }	\
	inline Vec3<float> NAME(const Vec3<float>& v3)			\
	{ return Vec3<float>(									\
		STDNAME(v3.X),										\
		STDNAME(v3.Y),										\
		STDNAME(v3.Z)); }									\
	inline Vec4<float> NAME(const Vec4<float>& v4)			\
	{ return Vec4<float>(									\
		STDNAME(v4.X),										\
		STDNAME(v4.Y),										\
		STDNAME(v4.Z),										\
		STDNAME(v4.W)); }

#define HX_STDMATH_MAKE_TEMPLATE_FUNCTION2(NAME, STDNAME)		\
	template<typename T>										\
	inline T NAME(T a, T b)										\
	{ return STDNAME(static_cast<T>(a), static_cast<T>(b)); }	\
	template<typename T>										\
	inline Vec2<T> NAME(const Vec2<T>& a, const Vec2<T>& b)		\
	{ return Vec2<T>(											\
		STDNAME(static_cast<T>(a.X), static_cast<T>(b.X)),		\
		STDNAME(static_cast<T>(a.Y), static_cast<T>(b.Y))); }	\
	template<typename T>										\
	inline Vec3<T> NAME(const Vec3<T>& a, const Vec3<T>& b)		\
	{ return Vec3<T>(											\
		STDNAME(static_cast<T>(a.X), static_cast<T>(b.X)),		\
		STDNAME(static_cast<T>(a.Y), static_cast<T>(b.Y)),		\
		STDNAME(static_cast<T>(a.Z), static_cast<T>(b.Z))); }	\
	template<typename T>										\
	inline Vec4<T> NAME(const Vec4<T>& a, const Vec4<T>& b)		\
	{ return Vec4<T>(											\
		STDNAME(static_cast<T>(a.X), static_cast<T>(b.X)),		\
		STDNAME(static_cast<T>(a.Y), static_cast<T>(b.Y)),		\
		STDNAME(static_cast<T>(a.Z), static_cast<T>(b.Z)),		\
		STDNAME(static_cast<T>(a.W), static_cast<T>(b.W))); }

#define HX_STDMATH_MAKE_FLOAT_FUNCTION2(NAME, STDNAME)						\
	inline float NAME(float a, float b)										\
	{ return STDNAME(a, b); }												\
	inline Vec2<float> NAME(const Vec2<float>& a, const Vec2<float>& b)		\
	{ return Vec2<float>(													\
		STDNAME(a.X, b.X),													\
		STDNAME(a.Y, b.Y)); }												\
	inline Vec3<float> NAME(const Vec3<float>& a, const Vec3<float>& b)		\
	{ return Vec3<float>(													\
		STDNAME(a.X, b.X),													\
		STDNAME(a.Y, b.Y),													\
		STDNAME(a.Z, b.Z)); }												\
	inline Vec4<float> NAME(const Vec4<float>& a, const Vec4<float>& b)		\
	{ return Vec4<float>(													\
		STDNAME(a.X, b.X),													\
		STDNAME(a.Y, b.Y),													\
		STDNAME(a.Z, b.Z),													\
		STDNAME(a.W, b.W)); }

namespace Hx { namespace Math {

	HX_STDMATH_MAKE_TEMPLATE_FUNCTION2(Modulo, std::fmod)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION2(Remainder, std::remainder)


	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Sin, std::sin)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Cos, std::cos)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Tan, std::tan)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Arctan, std::atan)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION2(Arctan2, std::atan2)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Arccos, std::acos)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Arcsin, std::asin)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Sinh, std::sinh)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Cosh, std::cosh)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Tanh, std::tanh)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Arcsinh, std::asinh)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Arccosh, std::acosh)
	HX_STDMATH_MAKE_TEMPLATE_FUNCTION1(Arctanh, std::atanh)
	
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Sin, sinf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Cos, cosf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Tan, tanf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Arctan, atanf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION2(Arctan2, atan2f)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Arccos, acosf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Arcsin, asinf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Sinh, sinhf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Cosh, coshf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Tanh, tanhf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Arctanh, atanhf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Arccosh, acoshf)
	HX_STDMATH_MAKE_FLOAT_FUNCTION1(Arcsinh, asinhf)

}}

#undef HX_STDMATH_MAKE_TEMPLATE_FUNCTION1
#undef HX_STDMATH_MAKE_TEMPLATE_FUNCTION2

#undef HX_STDMATH_MAKE_FLOAT_FUNCTION1
#undef HX_STDMATH_MAKE_FLOAT_FUNCTION2
