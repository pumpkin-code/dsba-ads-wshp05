/*! \file matrix.h
 *  Contains declaration of the clas Matrix and corresponding types.
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstddef> // size_t
#include <iostream>


/*! ******************************************************************
 *  \brief The Matrix class represents a matrix of floating-point
 *  numbers.
 ********************************************************************/


class Matrix {
public:
    typedef std::vector<double> MatrixVector;
    typedef MatrixVector RowVector;
    typedef MatrixVector ColVector;
    typedef std::vector<RowVector> VectorOfRows;
    typedef std::pair<size_t, size_t> SizePair;



public:

    // When we do not define any constructorsin a class, then
    // the compiler creates the default one for us.
    // Since we add any other type of constructors, the default
    // constructor is not available anymore.
    Matrix() { }


    /// The initializing constuctor.
    Matrix(size_t m, size_t n, double def = 42);


    /// Resizes the current matrix up to m*n cells.
    /// \a def is a defualt value for each newly added cell.
    void resize(size_t m, size_t n, double def = 0);

    /// Overloaded version of the resize() method dispatching the packed size.
    /// We define the body of the method right here, which makes it inline.
    /*inline*/ void resize(const SizePair& sz, double def = 0)
    {
        /*this->*/resize(sz.first, sz.second, def);
    }

    // TODO: repair this method!
    /// Returns the size of the matrix object.
    SizePair getSize();


    /// \returns an i-th row of the matrix
    RowVector& getRow(size_t i);

    // TODO: add const overload for the method getRow()


    /// Creates an independant vector of size \a n and fills it in be \a def values.
    static MatrixVector createVector(size_t n, double def);

    // TODO: repair this method!
    /// \returns an individual i-tj, j-th element of the matrix.
    double getEl(size_t i, size_t j);

    /// sets the i-th, j-th element of a matrix to the given value \a val
    void setEl(size_t i, size_t j, double val);


    // TODO: implement the following operator:
    /// another approach for overloading the operator==
    /// the lhv operand is now passed by used the this pointer
    bool operator == (const Matrix& rhv) const;

    // TODO: implement the following operator:
    /// multiplies the matrix to a scalar
    Matrix& operator *= (double rhv) ;

    // TODO: implement the following operator:
    /// return a matrix which is formed by multiplication of the
    /// intital matrix to a scalar
    Matrix operator * (double rhv) const;

private:
    VectorOfRows _matrix;           ///< Internal storage.

}; // class Matrix


// TODO: implement the following operator:
/// Declaration of the output operator for printing pairs.
std::ostream& operator <<(std::ostream& s, const Matrix::SizePair& pr);

// TODO: implement the following operator:
/// output a matrix to the given stream \a s
std::ostream& operator<<(std::ostream& s, const Matrix& m);

// TODO: implement the following operator:
/// output a single vector to the given stream \a s
std::ostream& operator<<(std::ostream& s, const Matrix::MatrixVector& v);

//// / compares two matrices
//bool operator==(const Matrix& lhv, const Matrix& rhv);

// TODO: implement the following operator:
bool operator!=(const Matrix& lhv, const Matrix& rhv);



#endif // MATRIX_H
