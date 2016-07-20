# CircuitSimulator

C++ tool for determining electronic circuit's node voltages and currents using Modified Nodal Analysis:

https://www.swarthmore.edu/NatSci/echeeve1/Ref/mna/MNA1.html

The circuit can contain the independent voltage sources as well as inductors, capacitors and resistors.

##Requirements
* Armadillo library: http://arma.sourceforge.net/ 
 
## Input
The input characteristics of the circuit should be written in the file input.txt, which
has the following form:

| Element | 1st node | 2nd node | Value |
| --------|:--------:| --------:|-------|
| F       |          |         |  0.5  | 
| Vin     |     3    |      0   |  1.0  | 
| R1      |     1    |      0   |  1000.0 | 
| R2     |     3    |      2   |  1000.0  | 
| C1     |     1    |      0   |  1E-6  | 
| C2     |     2    |      1   |  1E-5  | 
| L1     |     1      |      0    |  0.001  | 

## Output

The function SystemSolve returns the vector (v_1,..v_n, i_1,..,i_m), where
v_1,..,v_n are voltages at each node and i_1, ..., i_m are currents throw each voltage source.

## Compilation
* qmake
* make

## Tests
File test.cpp contains the tests. 

In order to compile test.cpp:
* qmake -config test
* make
