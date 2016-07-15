#include "elementfactory.h"

Element * ElementFactory::CreateElement(std::string line)
{
// If code starts with "R" return new Resistor
// If code starts with "I" return new Inductance
// e.t.c
    // if error return 0

    Element * ee;

//    std::cout << "From CreateElement: " << line << '\n';

    std::string symb;
    int first, second;
    float value;

    std::stringstream ss(line);
    std::string item;

//    while (getline(ss, item, ' ')) {
//         std::cout << item << '\n';
//      }

    // Probably, it is better to combine symb, first, second and value and make a loop?

    getline(ss, item, ' ');
    symb = item;

    getline(ss, item, ' ');
    first = std::stoi(item);

    getline(ss, item, ' ');
    second = std::stoi(item);

    getline(ss, item, ' ');
    value = std::stof(item);

//    std::cout << "From  CreateElement " << symb << " " << first << " " << second << " " << value <<'\n';

    // Is switch construction is better here?

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

