#include "nodalmatrixsolver.h"

NodalMatrixSolver::NodalMatrixSolver(Circuit & my_circ)
{
    std::cout << "From NodalMatrixSolver " << '\n';
    int number = my_circ.GetNumberNodes();
    std::cout << "number of nodes " << number << '\n';
    for(int i = 0; i <= number; i++)
    {
        std::vector<std::vector<Element *>> row;

        for(int j = 0; j <= number; j++)
            row.push_back(my_circ.FindElements(i,j));

        ElementsBetween.push_back(row); // Why not  ElementsBetween->push_back(row); ?
    }
}


void NodalMatrixSolver::PrintElementsBetween(int nodesnumber)
{
    std::cout << "From PrintElementsBetween " << '\n';
    int elementsnumber;
      for(int i = 0; i <= nodesnumber; i++)
      {
          for(int j = 0; j <= nodesnumber; j++)
          {
              std::cout << "Nodes " << i << " and " << j << " ";
              elementsnumber = ElementsBetween[i][j].size();
              std::cout << "has " << elementsnumber << " elements in between " <<'\n';
              for(int k = 0; k < elementsnumber; k++)
                  ElementsBetween[i][j][k]->Print();
           }
       }
}



arma::cx_mat NodalMatrixSolver::constructA(int nodesnumber)
{
    arma::cx_mat A(nodesnumber, nodesnumber, arma::fill::zeros);
    int elementsnumber;

    double frequency = 0.5; // A Get method must be added to obtain frequency
    std::complex<double> invimped; // Why float does not work here?

    for(int i = 1; i <= nodesnumber; i++)
    {
        elementsnumber = ElementsBetween[i][0].size();
        for(int k = 0; k < elementsnumber; k++)
        {
            invimped = ElementsBetween[i][0][k]-> GetInverseImpedance(frequency);
            A(i-1,i-1) = A(i-1,i-1) + invimped;
        }
            for(int j = 1; j <= nodesnumber; j++)
            {

                if(i != j)
                {
                    ElementsBetween[1][2][0]->Print();
                    elementsnumber = ElementsBetween[i][j].size();

                    for(int k = 0; k < elementsnumber; k++)
                    {
                        invimped = ElementsBetween[i][j][k]-> GetInverseImpedance(frequency);
                        A(i-1,i-1) = A(i-1,i-1) + invimped;
                        A(i-1,j-1) = A(i-1,j-1) - invimped;
                    }
                }
            }

    }
    return A;
}
