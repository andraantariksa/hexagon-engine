#pragma once

#include <type_traits>

template <
	typename T,
	typename = typename std::enable_if<std::is_integral<T>::value>::type
>
class Vec2
{
	T X, Y;

	Vec2(T s = T(0));
	Vec2(T x, T y);
	Vec2(const Vec2<T>& other);

	Vec2<T>& operator=(const Vec2<T>& other);
	Vec2<T>& operator=(T s);

	Vec2<T>& operator+=(const Vec2<T>& other);
	Vec2<T>& operator-=(const Vec2<T>& ohter);
	Vec2<T>& operator*=(const Vec2<T>& other);
	Vec2<T>& operator/=(const Vec2<T>& other);

	Vec2<T>& operator+=(T s);
	Vec2<T>& operator-=(T s);
	Vec2<T>& operator*=(T s);
	Vec2<T>& operator/=(T s);

	Vec2<T> abs();
};

template<typename T, typename _>
inline Vec2<T, _>::Vec2(T s)
	: X(s), Y(s)
{
}

template<typename T, typename _>
inline Vec2<T, _>::Vec2(T x, T y)
	: X(s), Y(s)
{
}

template<typename T, typename _>
inline Vec2<T, _>::Vec2(const Vec2<T>& other)
	: X(other.x), Y(other.y)
{
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator=(const Vec2<T>& other)
{
	this->X = other.X;
	this->Y = other.Y;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator=(T s)
{
	this->X = s;
	this->Y = s;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator+=(const Vec2<T>& other)
{
	this->X += other.X;
	this->Y += other.Y;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator-=(const Vec2<T>& other)
{
	this->X -= other.X;
	this->Y -= other.Y;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator*=(const Vec2<T>& other)
{
	this->X *= other.X;
	this->Y *= other.Y;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator/=(const Vec2<T>& other)
{
	this->X /= other.X;
	this->Y /= other.Y;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator+=(T s)
{
	this->X += s;
	this->Y += s;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator-=(T s)
{
	this->X -= s;
	this->Y -= s;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator*=(T s)
{
	this->X *= s;
	this->Y *= s;
	return *this;
}

template<typename T, typename _>
inline Vec2<T>& Vec2<T, _>::operator/=(T s)
{
	this->X /= s;
	this->Y /= s;
	return *this;
}

template<typename T, typename _>
inline Vec2<T> operator+(const Vec2<T>& a, const Vec2<T>& b)
{
	return Vec2<T>(a.X + b.X, a.Y + b.Y);
}

template<typename T, typename _>
inline Vec2<T> operator-(const Vec2<T>& a, const Vec2<T>& b)
{
	return Vec2<T>(a.X - b.X, a.Y - b.Y);
}

template<typename T, typename _>
inline Vec2<T> operator*(const Vec2<T>& a, const Vec2<T>& b)
{
	return Vec2<T>(a.X * b.X, a.Y * b.Y);
}

template<typename T, typename _>
inline Vec2<T> operator/(const Vec2<T>& a, const Vec2<T>& b)
{
	return Vec2<T>(a.X / b.X, a.Y / b.Y);
}

template<typename T, typename _>
inline Vec2<T> operator+(const Vec2<T>& a, T b)
{
	return Vec2<T>(a.X + b, a.Y + b);
}

template<typename T, typename _>
inline Vec2<T> operator-(const Vec2<T>& a, T b)
{
	return Vec2<T>(a.X - b, a.Y - b);
}

template<typename T, typename _>
inline Vec2<T> operator*(const Vec2<T>& a, T b)
{
	return Vec2<T>(a.X * b, a.Y * b);
}

template<typename T, typename _>
inline Vec2<T> operator/(const Vec2<T>& a, T b)
{
	return Vec2<T>(a.X / b, a.Y / b);
}

template<typename T, typename _>
inline Vec2<T> operator+(T a, const Vec2<T>& b)
{
	return Vec2<T>(a + b.X, a + b.Y);
}

template<typename T, typename _>
inline Vec2<T> operator-(T a, const Vec2<T>& b)
{
	return Vec2<T>(a - b.X, a - b.Y);
}

template<typename T, typename _>
inline Vec2<T> operator*(T a, const Vec2<T>& b)
{
	return Vec2<T>(a * b.X, a * b.Y);
}

template<typename T, typename _>
inline Vec2<T> operator/(T a, const Vec2<T>& b)
{
	return Vec2<T>(a / b.X, a / b.Y);
}

template<typename T, typename _>
inline Vec2<T> Vec2<T, _>::abs()
{
	T x_result = (this->X < 0) ? x * -1 : x;
	T y_result = (this->Y < 0) ? y * -1 : y;
	return result;
}