#ifndef NODALMATRIXSOLVER_H
#define NODALMATRIXSOLVER_H

#include "circuit.h"
#include <armadillo>

class NodalMatrixSolver
{
public:
    NodalMatrixSolver(Circuit & my_circ);
    void PrintElementsBetween(int nodesnumber);
    arma::cx_mat constructG(Circuit & my_circ, float frequency);
    arma::cx_mat constructB(Circuit & my_circ);
    arma::cx_mat constructRHS(Circuit & my_circ);
    arma::cx_mat JoinMatrix(Circuit & my_circ, arma::cx_mat A, arma::cx_mat B);
    arma::cx_vec System_Solve(arma::cx_mat A, arma::cx_mat RHS);

protected:
    std::vector<std::vector<std::vector<Element*>>> ElementsBetween;

};

#endif // NODALMATRIXSOLVER_H
