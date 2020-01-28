// Implementation module for the Matrix class.
#include "matrix.h"


//------------------------------------------------------------------------------

Matrix::Matrix(size_t m, size_t n, double def)
{
    resize(m, n, def);
}

//------------------------------------------------------------------------------

void Matrix::resize(size_t m, size_t n, double def)
{
    if(m == 0 || n == 0)
        _matrix.clear();

    if(_matrix.size() != m)
    {
        size_t prevSize = _matrix.size();

        MatrixVector defVector = createVector(n, def);
        _matrix.resize(m, defVector);

    } // number of rows is changed

    if(_matrix[0].size() != n)
    {
        for(RowVector& row : _matrix)       // ref here is a must!
            row.resize(n, def);
    }
}


//------------------------------------------------------------------------------


Matrix::SizePair Matrix::getSize()
{
    if( !/*this->*/_matrix.size())
        return {0, 0}; // return std::make_pair(0, 0,);

    return {_matrix.size(), _matrix[0].size() };
}

//------------------------------------------------------------------------------

Matrix::RowVector& Matrix::getRow(size_t i)
{
    if(i >= _matrix.size())
        throw std::out_of_range("There no such a row.");

    return _matrix[i];
}

//------------------------------------------------------------------------------



//------------------------------------------------------------------------------

//static
Matrix::MatrixVector Matrix::createVector(size_t n, double def)
{
    //this->
    // std::vector<double>
    MatrixVector v(n, def);
    return v;
}

//------------------------------------------------------------------------------

double Matrix::getEl(size_t i, size_t j)
{
    const RowVector& row = getRow(i);

    return row.at(j);
}

//------------------------------------------------------------------------------

void Matrix::setEl(size_t i, size_t j, double val)
{
    RowVector& row = getRow(i);
    row.at(j) = val;
}



//------------------------------------------------------------------------------


//------------------------------------------------------------------------------




//------------------------------------------------------------------------------



//------------------------------------------------------------------------------



//------------------------------------------------------------------------------


//------------------------------------------------------------------------------



//------------------------------------------------------------------------------




//------------------------------------------------------------------------------


