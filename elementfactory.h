#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H
#include "elements.h"
#include <sstream>

class ElementFactory
{
public:
     Element * CreateElement(std::string code);

};

#endif // ELEMENTFACTORY_H
