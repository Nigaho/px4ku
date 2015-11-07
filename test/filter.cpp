#include <assert.h>
#include <stdio.h>

#include <matrix/filter.hpp>

using namespace matrix;

template class Vector<float, 5>;

int main()
{
    const size_t n_x = 6;
    const size_t n_y = 5;
    SquareMatrix<float, n_x> P = eye<float, n_x>();
    SquareMatrix<float, n_y> R = eye<float, n_y>();
    Matrix<float, n_y, n_x> C;
    C.setIdentity();
    float data[] = {1,2,3,4,5};
    Vector<float, n_y> r(data);

    Vector<float, n_x> dx;
    float beta = 0;
    kalman_correct<float, 6, 5>(P, C, R, r, dx, beta);

    dx.T().print();
    printf("beta: %g\n", beta);

    float data_check[] = {0.5,1,1.5,2,2.5,0};
    Vector<float, n_x> dx_check(data_check);
    assert(dx == dx_check);


    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
