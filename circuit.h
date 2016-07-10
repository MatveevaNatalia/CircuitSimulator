#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <vector>
//#include <armadillo>
#include <complex>

#include "elements.h"

class Circuit{
    std::vector<Element *> elements; // we did not allocate the memory,
                                     //   but it still work ???
public:

    void Print();

    void AddElement(Element* new_element);

    std::vector <Element*> FindElements(int first_node, int second_node);

    int GetNumberNodes();

    int GetNumberVoltage()

    // Nodal analysis

/*    std::complex<double> GetMatrixG(int i, int j, float frequency){
        std::vector<Element *> found_elements;
        found_elements = FindElements(i,j);

        if(i == j){


        } */

        //return sum of inverse impedances of ALL elements connected to
       // this node

       // (if i!=j ) return the sum (?) of the negative inverse impedances of the
        //elements
        // BETWEEN ith and jth node



    // for each element between i and j call GetInverseImpedance
    // and return their sum

//   }


    //std::complex<float> GetRightPart(int i)
};




#endif // CIRCUIT_H
