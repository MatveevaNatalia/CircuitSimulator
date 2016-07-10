#include <iostream>
#include <vector>
#include <armadillo>
#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <complex>

class Element {
public:
    virtual void Print() = 0; // Pure virtual method; the object Element can't be created
   // virtual void Print(){} // In this case the object Element can be created
    // Print() is not a constructor! Why it affects if the object Element
    //can be created or not ???



    // The if a virtual function present here it must present also in avery child
    //class ????


    virtual int GetFirstNode() = 0;
    virtual int GetSecondNode() = 0;

    virtual bool IsVoltage() = 0;

//    virtual complex<float> GetInverseImpedance(float frequency) = 0;


    // GetFirstNode() and GetSecondNode() are exactly the same for all elements.
    // Do we realy need the virtual functions for them - yes, because Eelement itself
    // does not know about Nodes at all

//    int Print_test(){
//        std::cout << " I am in class Element " << std::endl;
//    }



};

class Resistor : public Element {
     int node1, node2;
     double resistance;
public:
     Resistor(double number_resist, int number1, int number2);

     virtual void Print();

     virtual int GetFirstNode();

     virtual int GetSecondNode();

     virtual bool IsVoltage();

//     virtual complex<float> GetInverseImpedance(float frequency);
};

class EMF : public Element {
    int node1, node2;
    double voltage;
public:
    EMF(double number_voltage, int number1, int number2);
    virtual void Print();
    virtual int GetFirstNode();
    virtual int GetSecondNode();
    virtual bool IsVoltage();
//    virtual complex<float> GetInverseImpedance(float frequency);
};

class Capacitor : public Element {
    int node1, node2;
    double conductance;
public:
    Capacitor(double number_conductance, int number1, int number2);
    virtual void Print();
    virtual int GetFirstNode();
    virtual int GetSecondNode();
    virtual bool IsVoltage();

//    virtual complex<float> GetInverseImpedance(float frequency){
//        return (0,frequency*conductance);
//    }

};

class Inductor : public Element {
    int node1, node2;
    double inductance;
public:
    Inductor(double number_inductance, int number1, int number2);
     virtual void Print();

    virtual int GetFirstNode();
    virtual int GetSecondNode();
    virtual bool IsVoltage();

//    virtual complex<float> GetInverseImpedance(float frequency){
//        return (0,1/(frequency*inductance));
//    }
};






#endif // ELEMENTS_H
