#include <iostream>
#include <vector>
#include <armadillo>
#include <complex>

#include "circuit.h"
#include "elements.h"
#include "nodalmatrixsolver.h"
#include "elementfactory.h"

int main(int argc, char *argv[])
{
    float frequency;
    ElementFactory* my_factory;
    std::vector <Element*> elements;

    std::fstream filestr("input.txt", std::fstream::in | std::fstream::out);

    if (filestr.is_open())
    {
         while (!filestr.eof())
        {
             Element* element_temp;
            std::string line("");
            getline(filestr, line);

            if (line[0] == 'F')
            {
                 frequency = my_factory->GetFrequency(line);
            }
            else
            {
                if(!filestr.eof())
                {
                    element_temp = my_factory->CreateElement(line);
                    elements.push_back(element_temp);
                }
            }
         }
    }
    else
    {
      std::cout << "Error opening input.txt file";
    }
    filestr.close();

    int number_nodes;
    int number_voltages;

    Circuit* my_circ = new Circuit();

    for(int i  = 0; i < elements.size(); i++)
      my_circ->AddElement(elements[i]);

    my_circ->Print();

    number_nodes = my_circ->GetNumberNodes();
    number_voltages = my_circ->GetNumberVoltage();


    NodalMatrixSolver *my_solver = new NodalMatrixSolver(*my_circ);
    my_solver->PrintElementsBetween(number_nodes);


    arma::cx_mat G(number_nodes, number_nodes);
    G = my_solver->constructG(*my_circ, frequency);

    for(int i = 0; i < number_nodes; i++)
    {
        for(int j = 0; j < number_nodes; j++)
            std::cout << G(i,j) << " ";
        std::cout << std::endl;
    }

    arma::cx_mat B(number_nodes, number_voltages);
    B = my_solver->constructB(*my_circ);

    for(int i = 0; i < number_nodes; i++)
    {
        for(int j = 0; j < number_voltages; j++)
            std::cout << B(i,j) << " ";
        std::cout << std::endl;
    }

    arma::cx_mat RHS(number_nodes+number_voltages, 1);
    RHS = my_solver->constructRHS(*my_circ);

    for(int i = 0; i <(number_nodes + number_voltages); i++)
        std::cout << RHS(i,0) <<'\n';

    my_solver->JoinMatrix(*my_circ, G, B); */

    arma::cx_mat A(number_nodes+number_voltages, number_nodes+number_voltages);

    A = my_solver->JoinMatrix(*my_circ, G, B)

    for(int i = 0; i < number_nodes+number_voltages; i++)
    {
        for(int j = 0; j<number_nodes+number_voltages; j++)
        {
            std::cout << A(i,j) << " ";
        }
        std::cout << '\n';
    }

    arma::cx_vec Y(number_nodes+number_voltages);
    Y = my_solver->System_Solve(A, RHS);
    
    std::cout <<"Solution of system AY=Z" << '\n';
    for(int i = 0; i < number_nodes+number_voltages; i++)
    {
        std::cout << Y(i) << '\n';
    }
    
    return 0;
}
