#pragma once

#include <stdexcept>
#include <cstring>

namespace Hx { namespace Math {

	/// ## Example
	///
	/// ```
	/// Matrix<int, 2, 2> mat;
	/// ```
	template<typename T, size_t ROW, size_t COL>
	class Matrix
	{
	public:

		static constexpr size_t Rows = ROW;
		static constexpr size_t Columns = COL;

		/// Default constructor
		/// Create identity matrix if both row and column are equal, otherwise it will intialize it to zero
		Matrix()
		{
			if constexpr (ROW == COL)
			{
				for (size_t indexRow = 0; indexRow < ROW; ++indexRow)
				{
					this->Data[indexRow][indexRow] = T(1);
				}
			}
			else
			{
				std::memset(this->Data, 0, ROW * COL * sizeof(T));
			}
		}

		/// Initialize matrix from scalar value
		/// 
		Matrix(T s)
		{
			for (size_t indexRow = 0; indexRow < ROW; ++indexRow)
			{
				for (size_t indexCol = 0; indexCol < COL; ++indexCol)
				{
					this->Data[indexRow][indexCol] = s;
				}
			}
		}

		/// Constructing matrix from array
		/// It will copy the array to construct the matrix
		Matrix(const T** fromArray, size_t rowCount, size_t colCount)
		{
			size_t r = rowCount > ROW ? ROW : rowCount;
			size_t c = colCount > COL ? COL : colCount;

			for (size_t indexRow = 0; indexRow < r; ++indexRow)
			{
				T* cache = fromArray[indexRow]; // cache first!!

				for (size_t indexCol = 0; indexCol < c; ++indexCol)
				{
					this->Data[indexRow][indexCol] = cache[indexCol];
				}
			}
		}

		/// Safe matrix indexing
		T& Get(const size_t indexN, const size_t indexM)
		{
			if (!(this->LengthRowCheck(indexN) || this->LengthColCheck(indexM)))
			{
				throw std::out_of_range("Matrix indexing out of range");
			}

			return this->Data[indexN][indexM];
		}

		const T& Get(const size_t indexN, const size_t indexM) const
		{
			if (!(this->LengthRowCheck(indexN) || this->LengthColCheck(indexM)))
			{
				throw std::out_of_range("Matrix indexing out of range");
			}

			return this->Data[indexN][indexM];
		}

		T& operator()(size_t r, size_t c)
		{
			return this->Data[r][c];
		}

		const T& operator()(size_t r, size_t c) const
		{
			return this->Data[r][c];
		}

	private:
		T Data[ROW][COL];

		bool LengthRowCheck(const size_t indexRow)
		{
			return indexRow >= 0 && indexRow < ROW;
		}

		bool LengthColCheck(const size_t indexCol)
		{
			return indexCol >= 0 && indexCol < COL;
		}
	};

	template <typename T>
	using Matrix2x2 = Matrix<T, 2, 2>;
	template <typename T>
	using Matrix3x2 = Matrix<T, 3, 2>;
	template <typename T>
	using Matrix2x3 = Matrix<T, 2, 3>;
	template <typename T>
	using Matrix3x3 = Matrix<T, 3, 3>;
}}
