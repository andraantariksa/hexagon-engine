#pragma once

#ifndef HX_DEFINED_MATH_H
#error "Cannot use Vec4.h directly!"
#endif

#include "../Types.h"
#include <cmath>

namespace Hx { namespace Math {

	template<typename T>
	struct Vec4
	{
		T X, Y, Z, W;

		Vec4(T s = T(0));
		Vec4(T x, T y, T z, T w);
		Vec4(const Vec4<T>& other);
		template<typename OtherT>
		explicit Vec4(const Vec4<OtherT>& other);

		Vec4<T>& operator=(const Vec4<T>& other);
		template<typename OtherT>
		Vec4<T>& operator=(const Vec4<OtherT>& other);
		Vec4<T>& operator=(T s);

		Vec4<T>& operator+=(const Vec4<T>& other);
		Vec4<T>& operator-=(const Vec4<T>& ohter);
		Vec4<T>& operator*=(const Vec4<T>& other);
		Vec4<T>& operator/=(const Vec4<T>& other);

		Vec4<T>& operator+=(T s);
		Vec4<T>& operator-=(T s);
		Vec4<T>& operator*=(T s);
		Vec4<T>& operator/=(T s);

		Vec4<T> Abs();
		T Length();
		T LengthSq();
		Vec4<T> Normalized();
	};

	template<typename T>
	inline Vec4<T>::Vec4(T s)
		: X(s), Y(s), Z(s), W(s)
	{
	}

	template<typename T>
	inline Vec4<T>::Vec4(T x, T y, T z, T w)
		: X(x), Y(y), Z(z), W(w)
	{
	}

	template<typename T>
	inline Vec4<T>::Vec4(const Vec4<T>& other)
		: X(other.X), Y(other.Y), Z(other.Z), W(other.W)
	{
	}

	template<typename T>
	template<typename OtherT>
	inline Vec4<T>::Vec4(const Vec4<OtherT>& other)
		: X((T)other.X), Y((T)other.Y), Z((T)other.Z), W((T)other.W)
	{
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator=(const Vec4<T>& other)
	{
		this->X = other.X;
		this->Y = other.Y;
		this->Z = other.Z;
		this->W = other.W;
		return *this;
	}
	
	template<typename T>
	template<typename OtherT>
	inline Vec4<T>& Vec4<T>::operator=(const Vec4<OtherT>& other)
	{
		this->X = (T)other.X;
		this->Y = (T)other.Y;
		this->Z = (T)other.Z;
		this->W = (T)other.W;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator=(T s)
	{
		this->X = s;
		this->Y = s;
		this->Z = s;
		this->W = s;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator+=(const Vec4<T>& other)
	{
		this->X += other.X;
		this->Y += other.Y;
		this->Z += other.Z;
		this->W += other.W;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator-=(const Vec4<T>& other)
	{
		this->X -= other.X;
		this->Y -= other.Y;
		this->Z -= other.Z;
		this->W -= other.W;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator*=(const Vec4<T>& other)
	{
		this->X *= other.X;
		this->Y *= other.Y;
		this->Z *= other.Z;
		this->W *= other.W;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator/=(const Vec4<T>& other)
	{
		this->X /= other.X;
		this->Y /= other.Y;
		this->Z /= other.Z;
		this->W /= other.W;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator+=(T s)
	{
		this->X += s;
		this->Y += s;
		this->Z += s;
		this->W += s;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator-=(T s)
	{
		this->X -= s;
		this->Y -= s;
		this->Z -= s;
		this->W -= s;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator*=(T s)
	{
		this->X *= s;
		this->Y *= s;
		this->Z *= s;
		this->W *= s;
		return *this;
	}

	template<typename T>
	inline Vec4<T>& Vec4<T>::operator/=(T s)
	{
		this->X /= s;
		this->Y /= s;
		this->Z /= s;
		this->W /= s;
		return *this;
	}

	template<typename T>
	inline Vec4<T> Vec4<T>::Abs()
	{
		return Vec4<T>(
			this->X < 0 ? -this->X : this->X,
			this->Y < 0 ? -this->Y : this->Y,
			this->Z < 0 ? -this->Z : this->Z,
			this->W < 0 ? -this->W : this->W);
	}

	template<typename T>
	inline T Vec4<T>::Length()
	{
		T x2 = this->X * this->X;
		T y2 = this->Y * this->Y;
		T z2 = this->Z * this->Z;
		T w2 = this->W * this->W;
		return (T)std::sqrt(x2 + y2 + z2 + w2);
	}

	template<>
	inline float Vec4<float>::Length()
	{
		float x2 = this->X * this->X;
		float y2 = this->Y * this->Y;
		float z2 = this->Z * this->Z;
		float w2 = this->W * this->W;
		return sqrtf(x2 + y2 + z2 + w2);
	}

	template<typename T>
	inline T Vec4<T>::LengthSq()
	{
		T x2 = this->X * this->X;
		T y2 = this->Y * this->Y;
		T z2 = this->Z * this->Z;
		T w2 = this->W * this->W;
		return x2 + y2 + z2 + w2;
	}

	template<typename T>
	inline Vec4<T> Vec4<T>::Normalized()
	{
		T len = this->Length();
		return *this / len;
	}

	template<typename T>
	inline Vec4<T> operator+(const Vec4<T>& a, const Vec4<T>& b)
	{
		return Vec4<T>(a.X + b.X, a.Y + b.Y, a.Z + b.Z, a.W + b.W);
	}

	template<typename T>
	inline Vec4<T> operator-(const Vec4<T>& a, const Vec4<T>& b)
	{
		return Vec4<T>(a.X - b.X, a.Y - b.Y, a.Z - b.Z, a.W - b.W);
	}

	template<typename T>
	inline Vec4<T> operator*(const Vec4<T>& a, const Vec4<T>& b)
	{
		return Vec4<T>(a.X * b.X, a.Y * b.Y, a.Z * b.Z, a.W * b.W);
	}

	template<typename T>
	inline Vec4<T> operator/(const Vec4<T>& a, const Vec4<T>& b)
	{
		return Vec4<T>(a.X / b.X, a.Y / b.Y, a.Z / b.Z, , a.W / b.W);
	}

	template<typename T>
	inline Vec4<T> operator+(const Vec4<T>& a, T b)
	{
		return Vec4<T>(a.X + b, a.Y + b, a.Z + b, a.W + b);
	}

	template<typename T>
	inline Vec4<T> operator-(const Vec4<T>& a, T b)
	{
		return Vec4<T>(a.X - b, a.Y - b, a.Z - b, a.W - b);
	}

	template<typename T>
	inline Vec4<T> operator*(const Vec4<T>& a, T b)
	{
		return Vec4<T>(a.X * b, a.Y * b, a.Z * b, a.Z * b);
	}

	template<typename T>
	inline Vec4<T> operator/(const Vec4<T>& a, T b)
	{
		return Vec4<T>(a.X / b, a.Y / b, a.Z / b, a.W / b);
	}

	template<typename T>
	inline Vec4<T> operator+(T a, const Vec4<T>& b)
	{
		return Vec4<T>(a + b.X, a + b.Y, a + b.Z, a + b.W);
	}

	template<typename T>
	inline Vec4<T> operator-(T a, const Vec4<T>& b)
	{
		return Vec4<T>(a - b.X, a - b.Y, a - b.Z, a - b.W);
	}

	template<typename T>
	inline Vec4<T> operator*(T a, const Vec4<T>& b)
	{
		return Vec4<T>(a * b.X, a * b.Y, a * b.Z, a * b.W);
	}

	template<typename T>
	inline Vec4<T> operator/(T a, const Vec4<T>& b)
	{
		return Vec4<T>(a / b.X, a / b.Y, a / b.Z, a / b.W);
	}

	template<typename T>
	inline Vec4<T> operator+(const Vec4<T>& a)
	{
		return Vec4<T>(+a.X, +a.Y, +a.Z, +a.W);
	}

	template<typename T>
	inline Vec4<T> operator-(const Vec4<T>& a)
	{
		return Vec4<T>(-a.X, -a.Y, -a.Z, -a.W);
	}

	// ----------------------------------------------------------------------------------

	template<typename T>
	inline T Length(const Vec4<T>& v)
	{
		T x2 = v.X * v.X;
		T y2 = v.Y * v.Y;
		T z2 = v.Z * v.Z;
		T w2 = v.W * v.W;
		return (T)sqrt(x2 + y2 + z2 + w2);
	}

	inline float Length(const Vec4<float>& v)
	{
		float x2 = v.X * v.X;
		float y2 = v.Y * v.Y;
		float z2 = v.Z * v.Z;
		float w2 = v.W * v.W;
		return sqrtf(x2 + y2 + z2 + w2);
	}

	template<typename T>
	inline T LengthSq(const Vec4<T>& v)
	{
		T x2 = v.X * v.X;
		T y2 = v.Y * v.Y;
		T z2 = v.Z * v.Z;
		T w2 = v.W * v.W;
		return x2 + y2 + z2 + w2;
	}

	template<typename T>
	inline T Distance(const Vec4<T>& a, const Vec4<T>& b)
	{
		return Length(a - b);
	}

	template<typename T>
	inline T DotProduct(const Vec4<T>& a, const Vec4<T>& b)
	{
		T axbx = a.X * b.X;
		T ayby = a.Y * b.Y;
		T azbz = a.Z * b.Z;
		T awbw = a.W * b.W;
		return (axbx + ayby) + (azbz + awbw);
	}

	template<typename T>
	inline Vec4<T> CrossProduct(const Vec4<T>& a, const Vec4<T>& b, const Vec4<T>& c)
	{
		// 24 mul 14 add/sub
		T zwwz = b.Z * c.W - b.W * c.Z;
		T ywwy = b.Y * c.W - b.W * c.Y;
		T yzzy = b.Y * c.Z - b.Z * c.Y;
		T xwwx = b.X * c.W - b.W * c.X;
		T xyyx = b.X * c.Y - b.Y * c.X;
		T xzzx = b.X * c.Z - b.Z * c.X;

		T i =  a.Y * zwwz - a.Z * ywwy + a.W * yzzy;
		T j = -a.X * zwwz + a.Z * xwwx - a.W * xzzx;
		T k =  a.X * ywwy - a.Y * xwwx + a.W * xyyx;
		T l = -a.X * yzzy + a.Y * xzzx - a.Z * xyyx;

		return Vec4<T>(i, j, k, l);
	}

	using Vec4F = typename Vec4<float>;
	using Vec4D = typename Vec4<double>;
	using Vec4I = typename Vec4<int32>;
	using Vec4U = typename Vec4<uint32>;

}}
