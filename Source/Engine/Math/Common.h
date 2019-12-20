#pragma once

#include "../Types.h"
#include "Vec2.h"
#include "Vec3.h"

namespace Hx { namespace Math {

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

}}
