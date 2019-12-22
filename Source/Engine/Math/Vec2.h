#pragma once

#ifndef HX_DEFINED_MATH_H
#error "Cannot use Vec2.h directly!"
#endif

#include "../Types.h"
#include <cmath>

namespace Hx { namespace Math {

	template <typename T>
	struct Vec2
	{
		T X, Y;
	
		Vec2(T s = T(0));
		Vec2(T x, T y);
		Vec2(const Vec2<T>& other);
		template<typename OtherT>
		Vec2(const Vec2<OtherT>& other);
	
		Vec2<T>& operator=(const Vec2<T>& other);
		template<typename OtherT>
		Vec2<T>& operator=(const Vec2<OtherT>& other);
		Vec2<T>& operator=(T s);
	
		Vec2<T>& operator+=(const Vec2<T>& other);
		Vec2<T>& operator-=(const Vec2<T>& ohter);
		Vec2<T>& operator*=(const Vec2<T>& other);
		Vec2<T>& operator/=(const Vec2<T>& other);
	
		Vec2<T>& operator+=(T s);
		Vec2<T>& operator-=(T s);
		Vec2<T>& operator*=(T s);
		Vec2<T>& operator/=(T s);
	};
	
	template<typename T>
	inline Vec2<T>::Vec2(T s)
		: X(s), Y(s)
	{
	}
	
	template<typename T>
	inline Vec2<T>::Vec2(T x, T y)
		: X(x), Y(y)
	{
	}
	
	template<typename T>
	inline Vec2<T>::Vec2(const Vec2<T>& other)
		: X(other.X), Y(other.Y)
	{
	}

	template<typename T>
	template<typename OtherT>
	inline Vec2<T>::Vec2(const Vec2<OtherT>& other)
		: X((T)other.X), Y((T)other.Y)
	{
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator=(const Vec2<T>& other)
	{
		this->X = other.X;
		this->Y = other.Y;
		return *this;
	}

	template<typename T>
	template<typename OtherT>
	inline Vec2<T>& Vec2<T>::operator=(const Vec2<OtherT>& other)
	{
		this->X = (T)other.X;
		this->Y = (T)other.Y;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator=(T s)
	{
		this->X = s;
		this->Y = s;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator+=(const Vec2<T>& other)
	{
		this->X += other.X;
		this->Y += other.Y;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator-=(const Vec2<T>& other)
	{
		this->X -= other.X;
		this->Y -= other.Y;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator*=(const Vec2<T>& other)
	{
		this->X *= other.X;
		this->Y *= other.Y;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator/=(const Vec2<T>& other)
	{
		this->X /= other.X;
		this->Y /= other.Y;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator+=(T s)
	{
		this->X += s;
		this->Y += s;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator-=(T s)
	{
		this->X -= s;
		this->Y -= s;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator*=(T s)
	{
		this->X *= s;
		this->Y *= s;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T>& Vec2<T>::operator/=(T s)
	{
		this->X /= s;
		this->Y /= s;
		return *this;
	}
	
	template<typename T>
	inline Vec2<T> operator+(const Vec2<T>& a, const Vec2<T>& b)
	{
		return Vec2<T>(a.X + b.X, a.Y + b.Y);
	}
	
	template<typename T>
	inline Vec2<T> operator-(const Vec2<T>& a, const Vec2<T>& b)
	{
		return Vec2<T>(a.X - b.X, a.Y - b.Y);
	}
	
	template<typename T>
	inline Vec2<T> operator*(const Vec2<T>& a, const Vec2<T>& b)
	{
		return Vec2<T>(a.X * b.X, a.Y * b.Y);
	}
	
	template<typename T>
	inline Vec2<T> operator/(const Vec2<T>& a, const Vec2<T>& b)
	{
		return Vec2<T>(a.X / b.X, a.Y / b.Y);
	}
	
	template<typename T>
	inline Vec2<T> operator+(const Vec2<T>& a, T b)
	{
		return Vec2<T>(a.X + b, a.Y + b);
	}
	
	template<typename T>
	inline Vec2<T> operator-(const Vec2<T>& a, T b)
	{
		return Vec2<T>(a.X - b, a.Y - b);
	}
	
	template<typename T>
	inline Vec2<T> operator*(const Vec2<T>& a, T b)
	{
		return Vec2<T>(a.X * b, a.Y * b);
	}
	
	template<typename T>
	inline Vec2<T> operator/(const Vec2<T>& a, T b)
	{
		return Vec2<T>(a.X / b, a.Y / b);
	}
	
	template<typename T>
	inline Vec2<T> operator+(T a, const Vec2<T>& b)
	{
		return Vec2<T>(a + b.X, a + b.Y);
	}
	
	template<typename T>
	inline Vec2<T> operator-(T a, const Vec2<T>& b)
	{
		return Vec2<T>(a - b.X, a - b.Y);
	}
	
	template<typename T>
	inline Vec2<T> operator*(T a, const Vec2<T>& b)
	{
		return Vec2<T>(a * b.X, a * b.Y);
	}
	
	template<typename T>
	inline Vec2<T> operator/(T a, const Vec2<T>& b)
	{
		return Vec2<T>(a / b.X, a / b.Y);
	}

	template<typename T>
	inline Vec2<T> operator+(const Vec2<T>& a)
	{
		return Vec2<T>(+a.X, +a.Y);
	}

	template<typename T>
	inline Vec2<T> operator-(const Vec2<T>& a)
	{
		return Vec2<T>(-a.X, -a.Y);
	}

	// ----------------------------------------------------------------------------------

	template<typename T>
	inline T Length(const Vec2<T>& v)
	{
		T x2 = v.X * v.X;
		T y2 = v.Y * v.Y;
		return (T)std::sqrt(x2 + y2);
	}

	inline float Length(const Vec2<float>& v)
	{
		float x2 = v.X * v.X;
		float y2 = v.Y * v.Y;
		return sqrtf(x2 + y2);
	}

	template<typename T>
	inline T LengthSq(const Vec2<T>& v)
	{
		T x2 = v.X * v.X;
		T y2 = v.Y * v.Y;
		return x2 + y2;
	}

	template<typename T>
	inline T DotProduct(const Vec2<T>& a, const Vec2<T>& b)
	{
		T axbx = a.X * b.X;
		T ayby = a.Y * b.Y;
		return axbx + ayby;
	}
	
	typedef Vec2<float>		Vec2F;
	typedef Vec2<double>	Vec2D;
	typedef Vec2<int32>		Vec2I;
	typedef Vec2<uint32>	Vec2U;

}}
