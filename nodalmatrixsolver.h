#ifndef NODALMATRIXSOLVER_H
#define NODALMATRIXSOLVER_H

#include "circuit.h"
#include <armadillo>

class NodalMatrixSolver
{
public:
    NodalMatrixSolver(Circuit & my_circ);
    arma::cx_mat constructA(int nodesnumber);
    void PrintElementsBetween(int nodesnumber);
protected:
    std::vector<std::vector<std::vector<Element*>>> ElementsBetween;

    arma::cx_mat constructB();
    arma::cx_mat constructD();
    arma::cx_vec constructRHS();

};

#endif // NODALMATRIXSOLVER_H
