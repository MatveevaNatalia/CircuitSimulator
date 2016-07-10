#include <iostream>
#include <vector>
#include <armadillo>
#include <complex>

#include "circuit.h"
#include "elements.h"

//using namespace std;
using namespace arma;



//std::vector<float> FindFixedPoint(Circuit *, float frequency){
//    Mat< std::complex<float> > matrix;
//    for(i)
//         for(j)
//             matrix(i,j) = GetNodalMatrix(i,j, frequency)
//

//    for(i)
//  It must return the vector of voltage
//}

int main(int argc, char *argv[])
{

    int number = 3;


    Element * e1 = new Resistor(0.1, 0, 1);
    Element * e2 = new Capacitor(10, 1, 2);
    Element * e3 = new EMF(5, 1, 0); // The plus is connected to the first node
    Element * e4 = new Inductor(8, 0, 2);
    float frequency = 0.5;


    //Element * e4 = new EMF(10, 0, 1);
//    e1-> Print(); // Should print “Resistance 0.1 Ohm, connecting nodes 0 and 1”
//    e2-> Print(); // Should print “Resistance 10  Ohm, connecting nodes 1 and 2”
//    e3-> Print(); // Should print “EMF 5 Volts, connecting nodes 0 and 2”

    // Array of elements--------------------------------------------------
    // Array of pointers is the two-dimensional array
    // For Circuit_v1
    // In order to have the array of an arbitrary size one needs to declare
    // it properly
    // Element *El_array[3] = {e1, e2, e3};
    // cout <<  "Printing from the first element of array" << endl;
    // El_array[0]->Print();
    // Circuit *my_circ = new Circuit(El_array, number);
    // my_circ->Print();


    //---------With vector -------------------------------------------------------//

    // The simplest example with 3 integers

    //   std::vector <int> elements_int = {1, 2, 3};
    //   for (int i = 0; i < elements_int.size(); i++)
    //       std::cout << elements_int[i] << std::endl;


    //-----------------An example with Element* --------------------------------//

/*       std::vector <Element*> elements= {e1, e2, e3};
       for (int i = 0; i < elements.size(); i++)
           elements[i]-> Print();

       std::cout << "After adding an element: " << std::endl;
       elements.push_back(e4);
       for (int i = 0; i < elements.size(); i++)
           elements[i]-> Print(); */

    std::vector <Element*> elements= {e1, e2, e3, e4};
    //Circuit *my_circ = new Circuit(elements); //It is for the example with old
    //constructor
    Circuit *my_circ = new Circuit();
    //my_circ->Print();

   // std::cout << "After adding an element: " << std::endl;
    for(int i  = 0; i < elements.size(); i++)
      my_circ->AddElement(elements[i]);

    //my_circ->AddElement(e4);
    my_circ->Print();


    //  Make this work
    // my_circ->AddElement(e1);
    // my_circ->AddElement(e2);
    // my_circ->AddElement(e3);




    // Search for elements between nodes


//     std::vector <Element *> between01 =  my_circ->FindElements(0,1);
//     std::cout << "Elements between node 0 and node 1:\n";
//     for(int i=0; i< between01.size(); i++) {
//         between01[i]->Print();
//     }


//   Number of PushBack should be equal to the number of elements in the matrix to keep
//    its shape.
     std::vector<std::vector<std::vector<Element*>>> ElementsBetween;
     for(int i = 0; i < number; i++)
     {
         std::vector<std::vector<Element *>> row;

         for(int j = 0; j < number; j++)
             row.push_back(my_circ->FindElements(i,j));

         ElementsBetween.push_back(row); // Why not  ElementsBetween->push_back(row); ?
     }

    std::cout << "Test:" << std::endl;
//    ElementsBetween[1][1][0]->Print();
    ElementsBetween[1][0][0]->Print();
//    ElementsBetween[1][1][0]->Print();
//    std::cout << ElementsBetween[1][1].size() << std::endl;
    std::cout << ElementsBetween[1][0].size() << std::endl;
//    std::cout << ElementsBetween[1][0].size() << std::endl;
//    std::cout << ElementsBetween[1][1].size() << std::endl;

/*    cx_mat G(number, number);
    for(int i = 0; i < number; i++){
        for(int j = 0; j < number; j++){
              G(i,j) = GetMatrixG(i, j, frequency);
              cout << G(i,j) << " ";
        }
        cout << endl;
    }*/


// Initializing of the armadillo matrix
//    double *matrix = new double [block_size*block_size];
//    arma::mat arma_matrix( matrix, block_size, block_size, true, true );

//cout << "am: " << arma_matrix(1, 0) << endl;


    return 0;
}
