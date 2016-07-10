#include "circuit.h"
#include "elements.h"

void Circuit::Print()
{
    for(int i = 0; i < elements.size(); i++)
    {
        std::cout << "From Circuit: " << std::endl;
        elements[i]->Print();
    }
}

void Circuit::AddElement(Element* new_element)
{
    elements.push_back(new_element);
}


std::vector <Element*> Circuit::FindElements(int first_node, int second_node)
{
    std::vector<Element *> found_elements;
    int node1_temp, node2_temp;
    for(int i = 0; i < elements.size(); i++)
    {
        node1_temp = elements[i]->GetFirstNode();
        node2_temp = elements[i]->GetSecondNode();

        if( node1_temp == first_node && node2_temp == second_node)
            found_elements.push_back(elements[i]);

    }
    return found_elements;
}

int Circuit::GetNumberNodes()
{
    int node1, node2, nodesnumber = 0;
    for(int i = 0; i < elements.size(); i++)
    {
        node1 = elements[i]->GetFirstNode();
        node2 = elements[i]->GetSecondNode();
        if(node1 > node2 && node1 > nodesnumber)
            nodesnumber = node1;
        if(node2 > node1 && node2 > nodesnumber)
            nodesnumber = node2;

    }
    return nodesnumber;
}

int Circuit::GetNumberVoltage()
{
    int voltagenumber = 0;
    for(int i = 0; i < elements.size(); i++)
    {
        if (elements[i]->IsVoltage() == True)
            voltagenumber++;
    }
    return voltagenumber;
}