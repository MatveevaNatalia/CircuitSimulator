#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <vector>
#include <armadillo>
#include <complex>

class Element {
public:
    virtual void Print() = 0;
    virtual int GetFirstNode() = 0;
    virtual int GetSecondNode() = 0;
    virtual bool IsVoltage() = 0;

    virtual std::complex<float> GetInverseImpedance(float frequency) = 0;

    virtual float GetVoltage() = 0;

};

class Resistor : public Element {
     int node1, node2;
     float resistance;
public:
     Resistor(float number_resist, int number1, int number2);

     virtual void Print();

     virtual int GetFirstNode();

     virtual int GetSecondNode();

     virtual bool IsVoltage();

     virtual std::complex<float> GetInverseImpedance(float frequency);

     virtual float GetVoltage();
};

class EMF : public Element {
    int node1, node2;
    float voltage;
public:
    EMF(float number_voltage, int number1, int number2);
    virtual void Print();
    virtual int GetFirstNode();
    virtual int GetSecondNode();
    virtual bool IsVoltage();
    virtual std::complex<float> GetInverseImpedance(float frequency);
    virtual float GetVoltage();
};

class Capacitor : public Element {
    int node1, node2;
    float conductance;
public:
    Capacitor(float number_conductance, int number1, int number2);
    virtual void Print();
    virtual int GetFirstNode();
    virtual int GetSecondNode();
    virtual bool IsVoltage();
    virtual std::complex<float> GetInverseImpedance(float frequency);
    virtual float GetVoltage();
};

class Inductor : public Element
{
    int node1, node2;
    float inductance;
public:
    Inductor(float number_inductance, int number1, int number2);
     virtual void Print();

    virtual int GetFirstNode();
    virtual int GetSecondNode();
    virtual bool IsVoltage();
    virtual std::complex<float> GetInverseImpedance(float frequency);
    virtual float GetVoltage();

};

#endif // ELEMENTS_H
