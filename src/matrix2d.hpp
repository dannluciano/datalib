#ifndef _MATRIX2D_HPP_
#define _MATRIX2D_HPP_

#include <ostream>
#include <vector>

namespace dl {

// Two-dimensional rectangular matrix.
template <typename T>
class matrix2d {
  public:

    matrix2d()
        : rows_(0), cols_(0), matrix(0) {
    }

    matrix2d(unsigned num_rows, unsigned num_cols)
        : rows_(num_rows), cols_(num_cols), matrix(num_rows * num_cols) {
    }

    matrix2d(unsigned num_rows, unsigned num_cols, const T& init_value)
        : rows_(num_rows), cols_(num_cols), matrix(num_rows * num_cols, init_value) {
    }

    unsigned num_rows() const { return rows_; }
    unsigned num_cols() const { return cols_; }

    // Accessors: return element by row and column.
    T& operator() ( unsigned row, unsigned col) {
        return matrix[ index( row, col ) ];
    }

    const T& operator() ( unsigned row, unsigned col) const {
        return matrix[ index( row, col ) ];
    }

    T& at ( unsigned row, unsigned col) {
        return matrix[ index( row, col ) ];
    }

    const T& at ( unsigned row, unsigned col) const {
        return matrix[ index( row, col ) ];
    }

    unsigned index(unsigned row, unsigned col) const {
        return (col * rows_ + row);
    }

  private:
    unsigned rows_, cols_;
    std::vector<T> matrix;
};

}  // namespace dl

template <typename T>
inline
std::ostream& operator << (std::ostream& os, const dl::matrix2d<T>& m) {
    for( unsigned r = 0; r < m.num_rows(); ++r ) {
        for( unsigned c = 0; c < m.num_cols(); ++c ) {
            os << m(r,c);
        }
        os << std::endl;
    }
    return os;
}

#endif /* _MATRIX2D_HPP_ */
