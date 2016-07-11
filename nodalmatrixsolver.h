#ifndef NODALMATRIXSOLVER_H
#define NODALMATRIXSOLVER_H

#include "circuit.h"
#include <armadillo>

class NodalMatrixSolver
{
public:
    NodalMatrixSolver(Circuit & my_circ);
    void PrintElementsBetween(int nodesnumber);
    arma::cx_mat constructA(int nodesnumber);
    arma::cx_mat constructB(Circuit & my_circ);

protected:
    std::vector<std::vector<std::vector<Element*>>> ElementsBetween;


    arma::cx_mat constructD();
    arma::cx_vec constructRHS();

};

#endif // NODALMATRIXSOLVER_H
