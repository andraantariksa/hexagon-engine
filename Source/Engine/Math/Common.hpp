#pragma once

#ifndef HX_DEFINED_MATH_H
#error "Cannot use Vec2.h directly!"
#endif

#include "../Types.hpp"
#include "Vec2.hpp"
#include "Vec3.hpp"
#include <type_traits>

namespace Hx { namespace Math {

	static const double Pi = 3.14159265358979323846;
	static const double Radians = Pi / 180.0;
	static const double Degrees = 180.0 / Pi;

	template<typename T>
	inline T Abs(T x)
	{
		return x < 0 ? -x : x;
	}

	template<typename T>
	inline Vec2<T> Abs(const Vec2<T>& x)
	{
		return Vec2<T>(
			x.X < 0 ? -x.X : x.X,
			x.Y < 0 ? -x.Y : x.Y);
	}

	template<typename T>
	inline Vec3<T> Abs(const Vec3<T>& x)
	{
		return Vec3<T>(
			x.X < 0 ? -x.X : x.X,
			x.Y < 0 ? -x.Y : x.Y,
			x.Z < 0 ? -x.Z : x.Z);
	}

	template<typename T>
	inline T DegreesToRadians(const T& degrees)
	{
		return degrees * T(Radians);
	}

	template<typename T>
	inline T RadiansToDegrees(const T& radians)
	{
		return radians * T(Degrees);
	}

	template<typename T>
	inline T Min(T a, T b)
	{
		return a < b ? a : b;
	}

	template<typename T>
	inline Vec2<T> Min(const Vec2<T>& a, const Vec2<T>& b)
	{
		return Vec2<T>(
			a.X < b.X ? a.X : b.X,
			a.Y < b.Y ? a.Y : b.Y);
	}
	
	template<typename T>
	inline Vec3<T> Min(const Vec3<T>& a, const Vec3<T>& b)
	{
		return Vec3<T>(
			a.X < b.X ? a.X : b.X,
			a.Y < b.Y ? a.Y : b.Y,
			a.Z < b.Z ? a.Z : b.Z);
	}

	template<typename T>
	inline T Max(T a, T b)
	{
		return a > b ? a : b;
	}

	template<typename T>
	inline Vec2<T> Max(const Vec2<T>& a, const Vec2<T>& b)
	{
		return Vec2<T>(
			a.X > b.X ? a.X : b.X,
			a.Y > b.Y ? a.Y : b.Y);
	}

	template<typename T>
	inline Vec3<T> Max(const Vec3<T>& a, const Vec3<T>& b)
	{
		return Vec3<T>(
			a.X > b.X ? a.X : b.X,
			a.Y > b.Y ? a.Y : b.Y,
			a.Z > b.Z ? a.Z : b.Z);
	}

	template<typename T>
	inline T Clamp(const T& x, const T& min, const T& max)
	{
		return Min(Max(x, min), max);
	}

	template<typename T>
	inline T Saturate(const T& x)
	{
		return Clamp(x, T(0), T(1));
	}

	template<typename T, typename T2>
	inline T LinearInterpolation(const T& a, const T& b, const T2& x)
	{
		const T tx = T(x);
		return tx * a + (T(1) - tx) * b;
	}

}}
