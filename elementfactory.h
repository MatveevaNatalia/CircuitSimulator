#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H
#include "elements.h"
#include <sstream>

class ElementFactory
{
public:
     Element * CreateElement(std::string line);
     float GetFrequency(std::string line);
};

#endif // ELEMENTFACTORY_H
