#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <vector>

#include <complex>

#include "elements.h"

class Circuit{
    std::vector<Element *> elements;

public:

    void Print();

    void AddElement(Element* new_element);

    std::vector <Element*> FindElements(int first_node, int second_node);

    std::vector <Element*> FindVoltages();

    int GetNumberNodes();

    int GetNumberVoltage();

};

#endif // CIRCUIT_H
