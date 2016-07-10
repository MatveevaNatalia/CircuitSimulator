#ifndef ELEMENTFACTORY_H
#define ELEMENTFACTORY_H
#include "elements.h"

class ElementFactory
{
public:
    Element * CreateElement(std::string code);
};

#endif // ELEMENTFACTORY_H
