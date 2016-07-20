#include <iostream>
#include <vector>
#include <armadillo>
#include <complex>

#include "circuit.h"
#include "elements.h"
#include "nodalmatrixsolver.h"
#include "elementfactory.h"

void test1(){
    std::cout << "### Test 1 start" << std::endl;

    std::cout << "Creating the circuit ... " << std::endl;
    Circuit * circ = new Circuit();
    circ->AddElement( new EMF( 9, 1, 0 )     );
    circ->AddElement( new Resistor( 1, 1, 2) );
    circ->AddElement( new Resistor( 1, 2, 3) );
    circ->AddElement( new Resistor( 1, 3, 0) );
    circ->AddElement( new Resistor( 3, 1, 0) );

    float frequency = 0.5;

    std::cout << "Constructing the system ... " << std::endl;
    NodalMatrixSolver * solver = new NodalMatrixSolver(*circ);
    arma::cx_mat G   = solver->constructG(*circ, frequency);
    arma::cx_mat B   = solver->constructB(*circ);
    arma::cx_mat RHS = solver->constructRHS(*circ);
    arma::cx_mat A   = solver->JoinMatrix(*circ, G, B);

    std::cout << "Solving the system ... " << std::endl;
    arma::cx_vec Y   = solver->System_Solve(A, RHS);

    std::cout <<"Solution:" << std::endl;

    std::cout << "Expected = (9, 0), result = " << Y(0) << std::endl;
    std::cout << "Expected = (6, 0), result = " << Y(1) << std::endl;
    std::cout << "Expected = (3, 0), result = " << Y(2) << std::endl;

    std::cout << "### Test 1 end" << std::endl;
    std::cout << std::endl;
}

void test2(){
    std::cout << "### Test 2 start" << std::endl;

    std::cout << "Creating the circuit ... " << std::endl;
    Circuit * circ = new Circuit();
    circ->AddElement( new EMF( 3, 1, 0 )     );
    circ->AddElement( new EMF( 7, 2, 0 )     );
    circ->AddElement( new EMF(10, 4, 3 )     );
    circ->AddElement( new Resistor( 1, 1, 3) );
    circ->AddElement( new Resistor( 1, 2, 3) );
    circ->AddElement( new Resistor( 1, 4, 0) );

    float frequency = 0.5;

    std::cout << "Constructing the system ... " << std::endl;
    NodalMatrixSolver * solver = new NodalMatrixSolver(*circ);
    arma::cx_mat G   = solver->constructG(*circ, frequency);
    arma::cx_mat B   = solver->constructB(*circ);
    arma::cx_mat RHS = solver->constructRHS(*circ);
    arma::cx_mat A   = solver->JoinMatrix(*circ, G, B);

    std::cout << "Solving the system ... " << std::endl;
    arma::cx_vec Y   = solver->System_Solve(A, RHS);

    std::cout <<"Solution:" << std::endl;

    std::cout << "Expected = ( 3, 0), result = " << Y(0) << std::endl;
    std::cout << "Expected = ( 7, 0), result = " << Y(1) << std::endl;
    std::cout << "Expected = ( 0, 0), result = " << Y(2) << std::endl;
    std::cout << "Expected = (10, 0), result = " << Y(3) << std::endl;

    std::cout << "### Test 2 end" << std::endl;
    std::cout << std::endl;
}

void test3(){
    std::cout << "### Test 3 start" << std::endl;

    std::cout << "Creating the circuit ... " << std::endl;
    Circuit * circ = new Circuit();
    circ->AddElement( new EMF( 10, 3, 0 )     );
    circ->AddElement( new Capacitor( 2, 0, 1) );
    circ->AddElement( new Inductor( 4, 1, 2)  );
    circ->AddElement( new Resistor( 1, 2, 3)  );

    float frequency = 0.5;

    std::cout << "Constructing the system ... " << std::endl;
    NodalMatrixSolver * solver = new NodalMatrixSolver(*circ);
    arma::cx_mat G   = solver->constructG(*circ, frequency);
    arma::cx_mat B   = solver->constructB(*circ);
    arma::cx_mat RHS = solver->constructRHS(*circ);
    arma::cx_mat A   = solver->JoinMatrix(*circ, G, B);

    std::cout << "Solving the system ... " << std::endl;
    arma::cx_vec Y   = solver->System_Solve(A, RHS);

    std::cout <<"Solution:" << std::endl;

    std::cout << "Expected = (-5,-5), result = " << Y(0) << std::endl;
    std::cout << "Expected = ( 5, 5), result = " << Y(1) << std::endl;
    std::cout << "Expected = (10, 0), result = " << Y(2) << std::endl;

    std::cout << "### Test 2 end" << std::endl;
    std::cout << std::endl;
}


int main(int argc, char *argv[]){
    test1();
    test2();
    test3();
    return 0;
}
