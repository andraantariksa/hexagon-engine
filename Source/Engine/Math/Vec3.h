#pragma once

#ifndef HX_DEFINED_MATH_H
#error "Cannot use Vec3.h directly!"
#endif

#include "../Types.h"
#include <cmath>

namespace Hx { namespace Math {

	template <typename T>
	struct Vec3
	{
		T X, Y, Z;

		Vec3(T s = T(0));
		Vec3(T x, T y, T z);
		Vec3(const Vec3<T>& other);
		template<typename OtherT>
		Vec3(const Vec3<OtherT>& other);

		Vec3<T>& operator=(const Vec3<T>& other);
		template<typename OtherT>
		Vec3<T>& operator=(const Vec3<OtherT>& other);
		Vec3<T>& operator=(T s);

		Vec3<T>& operator+=(const Vec3<T>& other);
		Vec3<T>& operator-=(const Vec3<T>& ohter);
		Vec3<T>& operator*=(const Vec3<T>& other);
		Vec3<T>& operator/=(const Vec3<T>& other);

		Vec3<T>& operator+=(T s);
		Vec3<T>& operator-=(T s);
		Vec3<T>& operator*=(T s);
		Vec3<T>& operator/=(T s);
	};

	template<typename T>
	inline Vec3<T>::Vec3(T s)
		: X(s), Y(s), Z(s)
	{
	}

	template<typename T>
	inline Vec3<T>::Vec3(T x, T y, T z)
		: X(x), Y(y), Z(z)
	{
	}

	template<typename T>
	inline Vec3<T>::Vec3(const Vec3<T>& other)
		: X(other.X), Y(other.Y), Z(other.Z)
	{
	}

	template<typename T>
	template<typename OtherT>
	inline Vec3<T>::Vec3(const Vec3<OtherT>& other)
		: X((T)other.X), Y((T)other.Y), Z((T)other.Z)
	{
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator=(const Vec3<T>& other)
	{
		this->X = other.X;
		this->Y = other.Y;
		this->Z = other.Z;
		return *this;
	}
	
	template<typename T>
	template<typename OtherT>
	inline Vec3<T>& Vec3<T>::operator=(const Vec3<OtherT>& other)
	{
		this->X = (T)other.X;
		this->Y = (T)other.Y;
		this->Z = (T)other.Z;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator=(T s)
	{
		this->X = s;
		this->Y = s;
		this->Z = s;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator+=(const Vec3<T>& other)
	{
		this->X += other.X;
		this->Y += other.Y;
		this->Z += other.Z;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator-=(const Vec3<T>& other)
	{
		this->X -= other.X;
		this->Y -= other.Y;
		this->Z -= other.Z;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator*=(const Vec3<T>& other)
	{
		this->X *= other.X;
		this->Y *= other.Y;
		this->Z *= other.Z;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator/=(const Vec3<T>& other)
	{
		this->X /= other.X;
		this->Y /= other.Y;
		this->Z /= other.Z;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator+=(T s)
	{
		this->X += s;
		this->Y += s;
		this->Z += s;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator-=(T s)
	{
		this->X -= s;
		this->Y -= s;
		this->Z -= s;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator*=(T s)
	{
		this->X *= s;
		this->Y *= s;
		this->Z *= s;
		return *this;
	}

	template<typename T>
	inline Vec3<T>& Vec3<T>::operator/=(T s)
	{
		this->X /= s;
		this->Y /= s;
		this->Z /= s;
		return *this;
	}

	template<typename T>
	inline Vec3<T> operator+(const Vec3<T>& a, const Vec3<T>& b)
	{
		return Vec3<T>(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
	}

	template<typename T>
	inline Vec3<T> operator-(const Vec3<T>& a, const Vec3<T>& b)
	{
		return Vec3<T>(a.X - b.X, a.Y - b.Y, a.Z - b.Z);
	}

	template<typename T>
	inline Vec3<T> operator*(const Vec3<T>& a, const Vec3<T>& b)
	{
		return Vec3<T>(a.X * b.X, a.Y * b.Y, a.Z * b.Z);
	}

	template<typename T>
	inline Vec3<T> operator/(const Vec3<T>& a, const Vec3<T>& b)
	{
		return Vec3<T>(a.X / b.X, a.Y / b.Y, a.Z / b.Z);
	}

	template<typename T>
	inline Vec3<T> operator+(const Vec3<T>& a, T b)
	{
		return Vec3<T>(a.X + b, a.Y + b, a.Z + b);
	}

	template<typename T>
	inline Vec3<T> operator-(const Vec3<T>& a, T b)
	{
		return Vec3<T>(a.X - b, a.Y - b, a.Z - b);
	}

	template<typename T>
	inline Vec3<T> operator*(const Vec3<T>& a, T b)
	{
		return Vec3<T>(a.X * b, a.Y * b, a.Z * b);
	}

	template<typename T>
	inline Vec3<T> operator/(const Vec3<T>& a, T b)
	{
		return Vec3<T>(a.X / b, a.Y / b, a.Z / b);
	}

	template<typename T>
	inline Vec3<T> operator+(T a, const Vec3<T>& b)
	{
		return Vec3<T>(a + b.X, a + b.Y, a + b.Z);
	}

	template<typename T>
	inline Vec3<T> operator-(T a, const Vec3<T>& b)
	{
		return Vec3<T>(a - b.X, a - b.Y, a - b.Z);
	}

	template<typename T>
	inline Vec3<T> operator*(T a, const Vec3<T>& b)
	{
		return Vec3<T>(a * b.X, a * b.Y, a * b.Z);
	}

	template<typename T>
	inline Vec3<T> operator/(T a, const Vec3<T>& b)
	{
		return Vec3<T>(a / b.X, a / b.Y, a / b.Z);
	}

	template<typename T>
	inline T Length(const Vec3<T>& v)
	{
		T x2 = v.X * v.X;
		T y2 = v.Y * v.Y;
		T z2 = v.Z * v.Z;
		return (T)std::sqrt(x2 + y2 + z2);
	}

	inline float Length(const Vec3<float>& v)
	{
		float x2 = v.X * v.X;
		float y2 = v.Y * v.Y;
		float z2 = v.Z * v.Z;
		return std::sqrtf(x2 + y2 + z2);
	}

	template<typename T>
	inline T LengthSq(const Vec3<T>& v)
	{
		T x2 = v.X * v.X;
		T y2 = v.Y * v.Y;
		T z2 = v.Z * v.Z;
		return x2 + y2 + z2;
	}

	template<typename T>
	inline T DotProduct(const Vec3<T>& a, const Vec3<T>& b)
	{
		T axbx = a.X * b.X;
		T ayby = a.Y * b.Y;
		T azbz = a.Z * b.Z;
		return (T)std::sqrt(axbx + ayby + azbz);
	}

	inline float DotProduct(const Vec3<float>& a, const Vec3<float>& b)
	{
		float axbx = a.X * b.X;
		float ayby = a.Y * b.Y;
		float azbz = a.Z * b.Z;
		return std::sqrtf(axbx + ayby + azbz);
	}

	template<typename T>
	inline Vec3<T> CrossProduct(const Vec3<T>& a, const Vec3<T>& b)
	{
		T i = a.Y * b.Z - a.Z * b.Y;
		T j = a.Z * b.X - a.X * b.Z;
		T k = a.X * b.Y - a.Y * b.X;
		return Vec3<T>(i, j, k);
	}

	typedef Vec3<float>		Vec3F;
	typedef Vec3<double>	Vec3D;
	typedef Vec3<int32>		Vec3I;
	typedef Vec3<uint32>	Vec3U;

}}
