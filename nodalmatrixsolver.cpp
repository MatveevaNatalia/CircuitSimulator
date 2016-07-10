#include "nodalmatrixsolver.h"

NodalMatrixSolver::NodalMatrixSolver(Circuit & my_circ)
{
    for(int i = 0; i < number; i++)
    {
        std::vector<std::vector<Element *>> row;

        for(int j = 0; j < number; j++)
            row.push_back(my_circ->FindElements(i,j));

        my_circ.push_back(row);
    }
}
