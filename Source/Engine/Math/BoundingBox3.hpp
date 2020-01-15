#pragma once

#include "Vec3.hpp"

namespace Hx { namespace Math {

	template<typename T>
	struct BoundingBox3
	{
		Vec3<T> Min, Max;

		BoundingBox3();
		BoundingBox3(T x, T y, T z);
		BoundingBox3(T minX, T minY, T minZ, T maxX, T maxY, T maxZ);
		BoundingBox3(const Vec3<T>& p);
		BoundingBox3(const Vec3<T>& min, const Vec3<T>& max);
		BoundingBox3(const Vec3<T>& center, const Vec3<T>& extents, T scale);
		BoundingBox3(const BoundingBox3<T>& other);
		template<typename OtherT>
		BoundingBox3(const BoundingBox3<OtherT>& other);
		~BoundingBox3();

		BoundingBox3<T>& operator=(const BoundingBox3<T>& other);
		template<typename OtherT>
		BoundingBox3<T>& operator=(const BoundingBox3<OtherT>& other);

		bool Intersects(const Vec3<T>& p);
		bool Intersects(const BoundingBox3<T>& bbox);

		Vec3<T> GetCenter();
	};

	template<typename T>
	inline BoundingBox3<T>::BoundingBox3()
		: Min(T(1)), Max(T(-1))
	{
	}

	template<typename T>
	inline BoundingBox3<T>::BoundingBox3(T x, T y, T z)
		: Min(x, y, z), Max(x, y, z)
	{
	}

	template<typename T>
	inline BoundingBox3<T>::BoundingBox3(T minX, T minY, T minZ, T maxX, T maxY, T maxZ)
		: Min(minX, minY, minZ), Max(maxX, maxY, maxZ)
	{
	}

	template<typename T>
	inline BoundingBox3<T>::BoundingBox3(const Vec3<T>& p)
		: Min(p.X, p.Y, p.Z), Max(p.X, p.Y, p.Z)
	{
	}

	template<typename T>
	inline BoundingBox3<T>::BoundingBox3(const Vec3<T>& min, const Vec3<T>& max)
		: Min(min.X, min.Y, min.Z), Max(max.X, max.Y, max.Z)
	{
	}

	template<typename T>
	inline BoundingBox3<T>::BoundingBox3(const Vec3<T>& center, const Vec3<T>& extents, T scale)
		: Min(center - extents * scale),
		Max(center + extents * scale)
	{
	}

	template<typename T>
	inline BoundingBox3<T>::BoundingBox3(const BoundingBox3<T>& other)
		: Min(other.Min), Max(other.Max)
	{
	}

	template<typename T>
	template<typename OtherT>
	inline BoundingBox3<T>::BoundingBox3(const BoundingBox3<OtherT>& other)
		: Min(other.Min), Max(other.Max)
	{
	}

	template<typename T>
	inline BoundingBox3<T>::~BoundingBox3()
	{
	}

	template<typename T>
	inline BoundingBox3<T>& BoundingBox3<T>::operator=(const BoundingBox3<T>& other)
	{
		this->Min = other.Min;
		this->Max = other.Max;
		return *this;
	}

	template<typename T>
	template<typename OtherT>
	inline BoundingBox3<T>& BoundingBox3<T>::operator=(const BoundingBox3<OtherT>& other)
	{
		this->Min = other.Min;
		this->Max = other.Max;
		return *this;
	}

	template<typename T>
	inline bool BoundingBox3<T>::Intersects(const Vec3<T>& p)
	{
		if (p.X < this->Min.X || p.X > this->Max.X)
		{
			return false;
		}

		if (p.Y < this->Min.Y || p.Y > this->Max.Y)
		{
			return false;
		}

		if (p.Z < this->Min.Z || p.Z > this->Max.Z)
		{
			return false;
		}

		return true;
	}

	template<typename T>
	inline bool BoundingBox3<T>::Intersects(const BoundingBox3<T>& bbox)
	{
		if (bbox.Min.X < this->Min.X || bbox.Max.X > this->Max.X)
		{
			return false;
		}

		if (bbox.Min.Y < this->Min.Y || bbox.Max.Y > this->Max.Y)
		{
			return false;
		}

		if (bbox.Min.Z < this->Min.Z || bbox.Max.Z > this->Max.Z)
		{
			return false;
		}

		return true;
	}

	template<typename T>
	inline Vec3<T> BoundingBox3<T>::GetCenter()
	{
		return (max - min) * T(0.5);
	}

	using BoundingBox3F = BoundingBox3<float>;
	using BoundingBox3D = BoundingBox3<double>;
	using BoundingBox3I = BoundingBox3<int32>;
	using BoundingBox3U = BoundingBox3<uint32>;

}}
