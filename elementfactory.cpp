#include "elementfactory.h"

Element * ElementFactory::CreateElement(std::string line)
{
    Element * ee;
    std::string symb;
    int first, second;
    float value;

    std::stringstream ss(line);
    std::string item;

    getline(ss, item, ' ');
    symb = item;

    getline(ss, item, ' ');
    first = std::stoi(item);

    getline(ss, item, ' ');
    second = std::stoi(item);

    getline(ss, item, ' ');
    value = std::stof(item);

    if(symb[0] == 'R')
        ee = new Resistor(value, first, second);
    if(symb[0] == 'L')
        ee = new Inductor(value, first, second);
    if(symb[0] == 'C')
        ee = new Capacitor(value, first, second);
    if(symb[0] == 'V')
        ee = new EMF(value, first, second);

    return ee;
}


float ElementFactory::GetFrequency(std::string line)
{
    float frequency;
    std::stringstream ss(line);
    std::string item;
    getline(ss, item, ' ');
    getline(ss, item, ' ');
    frequency = std::stof(item);

    return frequency;
}

