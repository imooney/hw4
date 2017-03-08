//  complex.h
//  Created by Isaac Mooney on 3/6/17.

#ifndef complex_h
#define complex_h

#include <iostream>

using namespace std;

class complex {
private:
    double *vec;
    const int size = 2;
public:
    complex(); //default constructor
    complex(double *loc);
    complex(const complex & vec); //copy constructor
    
    ~complex() {delete vec; vec = NULL;} //destructor
    
    //overloaded operators
    complex operator += (complex &);
    complex operator -= (complex &);
    complex operator + (complex &);
    complex operator - (complex &);
    complex operator * (complex &);
    double & operator [] (const int &);
    const complex &operator = (const complex &);
    
    //setter functions
    void Set(int index, double value) {
        if (index < size) {
            vec[index] = value;
        }
        else {cerr << "You're out of bounds." << '\n';}
    }
    
    //getter functions
    double Get(int index) {
        if (index < size) {
            return vec[index];
        }
        else {cerr << "You're out of bounds." << '\n'; exit(1);}
    }
    
    //member functions
    void Print();
    double Length();
};

#endif /* complex_h */
