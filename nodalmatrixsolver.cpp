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



arma::cx_mat NodalMatrixSolver::constructG(Circuit & my_circ, float frequency)
{
    int nodesnumber = my_circ.GetNumberNodes();
    arma::cx_mat G(nodesnumber, nodesnumber, arma::fill::zeros);
    int elementsnumber;

//    double frequency = 0.5; // A Get method must be added to obtain frequency
    std::complex<double> invimped; // Why float does not work here?

    for(int i = 1; i <= nodesnumber; i++)
    {
        elementsnumber = ElementsBetween[i][0].size();
        for(int k = 0; k < elementsnumber; k++)
        {
            invimped = ElementsBetween[i][0][k]-> GetInverseImpedance(frequency);
            G(i-1,i-1) = G(i-1,i-1) + invimped;
        }
            for(int j = 1; j <= nodesnumber; j++)
            {

                if(i != j)
                {

                    elementsnumber = ElementsBetween[i][j].size();

                    for(int k = 0; k < elementsnumber; k++)
                    {
                        invimped = ElementsBetween[i][j][k]-> GetInverseImpedance(frequency);
                        G(i-1,i-1) = G(i-1,i-1) + invimped;
                        G(i-1,j-1) = G(i-1,j-1) - invimped;
                    }
                }
            }

    }
    return G;
}

arma::cx_mat NodalMatrixSolver::constructB(Circuit & my_circ)
{
    int nodesnumber = my_circ.GetNumberNodes();
    int voltagenumber = my_circ.GetNumberVoltage();
    arma::cx_mat B(nodesnumber,voltagenumber, arma::fill::zeros);

    std::vector<Element*> Voltages;

    Voltages = my_circ.FindVoltages();

    int first_node, second_node;

    for(int i = 1; i <= nodesnumber; i++)
    {
        for(int j = 0; j < voltagenumber; j++)
        {
            first_node = Voltages[j]->GetFirstNode();
            second_node = Voltages[j]->GetSecondNode();
            if(i == first_node)
            {
                B(i-1,j) = 1;
            }
            else if (i == second_node)
            {
                B(i-1, j) = -1;
            }
            else
            {
                B(i-1,j) = 0;
            }
        }
    }

    return B;
}

arma::cx_mat NodalMatrixSolver::constructRHS(Circuit & my_circ)
{
    int nodesnumber = my_circ.GetNumberNodes();
    int voltagenumber = my_circ.GetNumberVoltage();
    arma::cx_mat RHS((nodesnumber+ voltagenumber),1, arma::fill::zeros);

    std::vector<Element*> Voltages;

    Voltages = my_circ.FindVoltages();

    float voltage;

    for(int i = 0; i < voltagenumber; i++)
    {
        voltage = Voltages[i]->GetVoltage();
        RHS(i+nodesnumber, 0) = voltage;
    }

    return RHS;
}


arma::cx_mat NodalMatrixSolver::JoinMatrix(Circuit & my_circ, arma::cx_mat G, arma::cx_mat B)
{
    int voltagenumber = my_circ.GetNumberVoltage();

    arma::cx_mat X = join_rows(G,B);

    arma::cx_mat C = strans(B);
    arma::cx_mat D(voltagenumber, voltagenumber, arma::fill::zeros);

    arma::cx_mat Y = join_rows(C, D);

    arma::cx_mat A = join_cols(X,Y);

//    int n_col = A.n_cols;
//    int n_row = A.n_rows;

    return A;
}

arma::cx_vec NodalMatrixSolver::System_Solve(arma::cx_mat A, arma::cx_mat RHS)
{
    arma::cx_vec Y  = solve(A, RHS);
    return Y;
}

















