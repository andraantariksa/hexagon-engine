#pragma once

#include <stdexcept>
#include <cstring>

namespace Hx { namespace Math {
    
    /// ## Example
    ///
    /// ```
    /// Matrix<int, 2, 2> mat;
    /// ```
    template<typename T, std::size_t ROW, std::size_t COL>
    class Matrix
    {
        private:
            T Data[ROW][COL];

            inline bool LengthRowCheck(const std::size_t IndexRow)
            {
                return IndexRow < ROW && IndexRow >= 0;
            }

            inline bool LengthColCheck(const std::size_t IndexCol)
            {
                return IndexCol < COL && IndexCol >= 0;
            }
        public:
            /// Default constructor
            /// It will set all of the matrix value as 0
            Matrix()
            {
                std::memset(this->Data, 0, sizeof(this->Data));
            }

            /// Constructing matrix from array
            /// It will copy the array to construct the matrix
            Matrix(const T FromArray[ROW][COL])
            {
                for (std::size_t IndexRow = 0; IndexRow < ROW; ++IndexRow)
                {
                    for (std::size_t IndexCol = 0; IndexCol < COL; ++IndexCol)
                    {
                        this->Data[IndexRow][IndexCol] = FromArray[IndexRow][IndexCol];
                    }
                }
            }

            const std::size_t LengthRow()
            {
                return ROW;
            }

            const std::size_t LengthCol()
            {
                return COL;
            }

            /// Safe matrix indexing
            T Get(const std::size_t IndexN, const std::size_t IndexM)
            {
                if (!this->LengthRowCheck(IndexN) || !this->LengthColCheck(IndexM))
                {
                    throw std::out_of_range("Matrix indexing out of range");
                }
                return this->Data[IndexN][IndexM];
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