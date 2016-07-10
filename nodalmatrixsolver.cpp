#include "nodalmatrixsolver.h"

NodalMatrixSolver::NodalMatrixSolver(Circuit & my_circ)
{
    int number = my_circ.GetNumberNodes();
    for(int i = 0; i < number; i++)
    {
        std::vector<std::vector<Element *>> row;

        for(int j = 0; j < number; j++)
            row.push_back(my_circ.FindElements(i,j));

        ElementsBetween.push_back(row);
    }
}

arma::cx_mat NodalMatrixSolver::constructA(Circuit & my_circ)
{

    int nodesnumber = my_circ.GetNumberNodes();

    arma::cx_mat A(nodesnumber-1, nodesnumber-1, arma::fill::zeros);
//    std::cout << "From NodalMatrixSolver: " << A(1,1) + A(1,1)<<std::endl;
    int elementsnumber;

    double frequency = 0.5; // A Get method must be added to obtain frequency
    std::complex<double> invimped; // Why float does not work here?

    for(int i = 1; i <= nodesnumber; i++)
    {
        elementsnumber = ElementsBetween[i][0].size();
        for(int k = 1; k <= elementsnumber; k++)
        {
            invimped = ElementsBetween[i][0][k]-> GetInverseImpedance(frequency);
            A(i-1,i-1) = A(i-1,i-1) + invimped;
        }
            for(int j = 1; j <= nodesnumber; j++)
            {

                elementsnumber = ElementsBetween[i][j].size();

                for(int k = 1; k <= elementsnumber; k++)
                {
                      invimped = ElementsBetween[i][j][k]-> GetInverseImpedance(frequency);
                      A(i-1,i-1) = A(i-1,i-1) + invimped;
                      A(i-1,j-1) = A(i-1,j-1) - invimped;

                }

            }

    }
    return A;
}
