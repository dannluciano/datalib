#ifndef _MATRIX3D_HPP_
#define _MATRIX3D_HPP_

#include <ostream>
#include <vector>

namespace dl {

// Three-dimensional rectangular matrix.
template <typename T>
class matrix3d {
  public:

    matrix3d()
        : rows_(0), cols_(0), pages_(0), matrix(0) {
    }

    matrix3d(unsigned num_rows, unsigned num_cols, unsigned num_pages)
        : rows_(num_rows), cols_(num_cols), pages_(num_pages), matrix(num_rows * num_cols * num_pages) {
    }

    matrix3d(unsigned num_rows, unsigned num_cols, unsigned num_pages, const T& init_value)
        : rows_(num_rows), cols_(num_cols), pages_(num_pages), matrix(num_rows * num_cols * num_pages, init_value) {
    }

    unsigned num_rows() const { return rows_; }
    unsigned num_cols() const { return cols_; }
    unsigned num_pages() const { return pages_; }

    // Accessors: return element by row and column.
    T& operator() ( unsigned row, unsigned col, unsigned page ) {
        return matrix[ index( row, col, page) ];
    }

    const T& operator() ( unsigned row, unsigned col, unsigned page ) const {
        return matrix[ index( row, col, page ) ];
    }

    T& at ( unsigned row, unsigned col, unsigned page ) {
        return matrix[ index( row, col, page) ];
    }

    const T& at ( unsigned row, unsigned col, unsigned page ) const {
        return matrix[ index( row, col, page ) ];
    }

    unsigned index(unsigned row, unsigned col, unsigned page) const {
        return (page * cols_ * rows_) + (col * rows_ + row);
    }

  private:
    unsigned rows_, cols_, pages_;
    std::vector<T> matrix;
};

}  // namespace dl

template <typename T>
inline
std::ostream& operator << (std::ostream& os, const dl::matrix3d<T>& m) {
    for( unsigned r = 0; r < m.num_rows(); ++r ) {
        for( unsigned c = 0; c < m.num_cols(); ++c ) {
            for (unsigned p = 0; p < m.num_pages(); ++p) {
                os << m(r,c, p);
            }
        }
        os << std::endl;
    }
    return os;
}

#endif /* _MATRIX3D_HPP_ */
