#pragma once

#include "Vec2.hpp"

namespace Hx { namespace Math {

	template<typename T>
	struct BoundingBox2
	{
		Vec2<T> Min, Max;

		BoundingBox2();
		BoundingBox2(T x, T y);
		BoundingBox2(T minX, T minY, T maxX, T maxY);
		BoundingBox2(const Vec2<T>& p);
		BoundingBox2(const Vec2<T>& min, const Vec2<T>& max);
		BoundingBox2(const Vec2<T>& center, const Vec2<T>& extents, T scale);
		BoundingBox2(const BoundingBox2<T>& other);
		template<typename OtherT>
		BoundingBox2(const BoundingBox2<OtherT>& other);
		~BoundingBox2();

		BoundingBox2<T>& operator=(const BoundingBox2<T>& other);
		template<typename OtherT>
		BoundingBox2<T>& operator=(const BoundingBox2<OtherT>& other);

		bool Intersects(const Vec2<T>& p);
		bool Intersects(const BoundingBox2<T>& bbox);

		Vec2<T> GetCenter();
	};

	template<typename T>
	inline BoundingBox2<T>::BoundingBox2()
		: Min(T(1)), Max(T(-1))
	{
	}

	template<typename T>
	inline BoundingBox2<T>::BoundingBox2(T x, T y)
		: Min(x, y), Max(x, y)
	{
	}

	template<typename T>
	inline BoundingBox2<T>::BoundingBox2(T minX, T minY, T maxX, T maxY)
		: Min(minX, minY), Max(maxX, maxY)
	{
	}

	template<typename T>
	inline BoundingBox2<T>::BoundingBox2(const Vec2<T>& p)
		: Min(p.X, p.Y), Max(p.X, p.Y)
	{
	}

	template<typename T>
	inline BoundingBox2<T>::BoundingBox2(const Vec2<T>& min, const Vec2<T>& max)
		: Min(min.X, min.Y), Max(max.X, max.Y)
	{
	}

	template<typename T>
	inline BoundingBox2<T>::BoundingBox2(const Vec2<T>& center, const Vec2<T>& extents, T scale)
		: Min(center - extents * scale),
		Max(center + extents * scale)
	{
	}

	template<typename T>
	inline BoundingBox2<T>::BoundingBox2(const BoundingBox2<T>& other)
		: Min(other.Min), Max(other.Max)
	{
	}

	template<typename T>
	template<typename OtherT>
	inline BoundingBox2<T>::BoundingBox2(const BoundingBox2<OtherT>& other)
		: Min(T(other.Min)), Max(T(other.Max))
	{
	}

	template<typename T>
	inline BoundingBox2<T>::~BoundingBox2()
	{
	}

	template<typename T>
	inline BoundingBox2<T>& BoundingBox2<T>::operator=(const BoundingBox2<T>& other)
	{
		this->Min = other.Min;
		this->Max = other.Max;
		return *this;
	}

	template<typename T>
	template<typename OtherT>
	inline BoundingBox2<T>& BoundingBox2<T>::operator=(const BoundingBox2<OtherT>& other)
	{
		this->Min = other.Min;
		this->Max = other.Max;
		return *this;
	}

	template<typename T>
	inline bool BoundingBox2<T>::Intersects(const Vec2<T>& p)
	{
		if (p.X < this->Min.X || p.X > this->Max.X)
		{
			return false;
		}

		if (p.Y < this->Min.Y || p.Y > this->Max.Y)
		{
			return false;
		}

		return true;
	}

	template<typename T>
	inline bool BoundingBox2<T>::Intersects(const BoundingBox2<T>& bbox)
	{
		if (bbox.Min.X < this->Min.X || bbox.Max.X > this->Max.X)
		{
			return false;
		}

		if (bbox.Min.Y < this->Min.Y || bbox.Max.Y > this->Max.Y)
		{
			return false;
		}

		return true;
	}

	template<typename T>
	inline Vec2<T> BoundingBox2<T>::GetCenter()
	{
		return (max - min) * T(0.5);
	}

	using BoundingBox2F = BoundingBox2<float>;
	using BoundingBox2D = BoundingBox2<double>;
	using BoundingBox2I = BoundingBox2<int32>;
	using BoundingBox2U = BoundingBox2<uint32>;

}}
