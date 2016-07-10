#include "elements.h"


Resistor::Resistor(double number_resist, int number1, int number2)
{
    node1 = number1;
    node2 = number2;
    resistance = number_resist;
}

void Resistor::Print()
{
     std::cout << "Resistor parameters: " << std::endl;
     std::cout << "The first node: " << node1 << std::endl;
     std::cout << "The second node: " << node2 << std::endl;
     std::cout << "Resistance: " << resistance << std::endl;
}

int Resistor::GetFirstNode()
{
     return node1;
}

int Resistor::GetSecondNode()
{
     return node2;
}

bool Resistor::IsVoltage()
{
    return 0;
}

complex<float> Resistor::GetInverseImpedance(float frequency)
{
    return (1/resistance,0);
}



EMF::EMF(double number_voltage, int number1, int number2)
{
    node1 = number1;
    node2 = number2;
    voltage = number_voltage;
}

void EMF::Print(){
    std::cout << "EMF parameters: " << std::endl;
    std::cout << "The first node: " << node1 << std::endl;
    std::cout << "The second node: " << node2 << std::endl;
    std::cout << "Voltage: " << voltage << std::endl;
}

int EMF::GetFirstNode(){
    int nodeGet = node1;
    return nodeGet;
}

int EMF::GetSecondNode(){
    int nodeGet = node2;
    return nodeGet;
}

bool EMF::IsVoltage()
{
    return 1;
}

complex<float> EMF::GetInverseImpedance(float frequency)
{
    return (0,0)
}


Capacitor::Capacitor(double number_conductance, int number1, int number2){
    node1 = number1;
    node2 = number2;
    conductance = number_conductance;
}

void Capacitor::Print(){
    std::cout << "Capacitor parameters: " << std::endl;
    std::cout << "The first node: " << node1 << std::endl;
    std::cout << "The second node: " << node2 << std::endl;
    std::cout << "Conductance: " << conductance << std::endl;
}

int Capacitor::GetFirstNode(){
    int nodeGet = node1;
    return nodeGet;
}

int Capacitor::GetSecondNode(){
    int nodeGet = node2;
    return nodeGet;
}

bool Capacitor::IsVoltage()
{
    return 0;
}

complex<float> Capacitor::GetInverseImpedance(float frequency)
{
    return (0,frequency*conductance);
}


Inductor::Inductor(double number_inductance, int number1, int number2)
{
    node1 = number1;
    node2 = number2;
    inductance = number_inductance;
}

void Inductor::Print()
{
    std::cout << "Inductor parameters: " << std::endl;
    std::cout << "The first node: " << node1 << std::endl;
    std::cout << "The second node: " << node2 << std::endl;
    std::cout << "Inductance: " << inductance << std::endl;
}

int Inductor::GetFirstNode()
{
    return node1;
}

int Inductor::GetSecondNode()
{
    return node2;
}

bool Inductor::IsVoltage()
{
    return 0;
}

complex<float> GetInverseImpedance(float frequency)
{
    return (0,1.0/(frequency*inductance));
}

