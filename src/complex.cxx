//  complex.cxx
//  Created by Isaac Mooney on 3/6/17.

#include "complex.h"

using namespace std;

#include "complex.h"
#include <iostream>
#include <cmath>

using namespace std;

complex::complex() {
    //default constructor - initializes complex number to 0
    vec = new double[size];
    for (int i = 0; i < size; ++ i) {
        vec[i] = 0;
    }
    //cout << "DEBUG: constructor 1" << endl;
    cout << "Default constructor called - initializes complex number c = 0 + 0i" << '\n';
}

complex::complex(double * loc) {
    //constructor for complex number with given values: c = vec[0] + vec[1]i
    vec = new double[size];
    for(int i = 0; i < size; ++ i) {
        vec[i] = loc[i];
    }
    //cout << "DEBUG: constructor 2" << endl;
}

complex::complex(const complex & copy) {
    //copy constructor
    vec = new double(copy.size);
    *vec = *copy.vec;
    //cout << "DEBUG: copy constructor" << endl;
}

complex complex::operator+=(complex & v) {
    //overloaded += operator
    for (int i = 0; i < v.size; ++ i) {
        vec[i] += v.Get(i);
    }
    //cout << "DEBUG: operator +=" << endl;
    return complex(vec);
}

complex complex::operator-=(complex & v) {
    //overloaded += operator
    for (int i = 0; i < v.size; ++ i) {
        vec[i] -= v.Get(i);
    }
    //cout << "DEBUG: operator -=" << endl;
    return complex(vec);
}

complex complex::operator+(complex & v) {
    //overloaded + operator
    double *added = new double[size];
    for (int i = 0; i < v.size; ++ i) {
        added[i] = vec[i] + v[i];
    }
    //cout << "DEBUG: operator +" << endl;
    return complex(added);
}

complex complex::operator-(complex & v) {
    //overloaded + operator
    double *subtracted = new double[size];
    for (int i = 0; i < v.size; ++ i) {
        subtracted[i] = vec[i] - v[i];
    }
    //cout << "DEBUG: operator +" << endl;
    return complex(subtracted);
}

complex complex::operator*(complex & v) {
    //overloaded + operator
    double *mult = new double[size];
    double foil_real = v[0]*vec[0] - v[1]*vec[1];
    double foil_im = v[0]*vec[1] + v[1]*vec[0];
    mult[0] = foil_real;
    mult[1] = foil_im;
    //cout << "DEBUG: operator *" << endl;
    return complex(mult);
}

double & complex::operator[](const int & index) {
    if (index < size) {
        //cout << "DEBUG: operator []" << endl;
        return vec[index];
    }
    else {cerr << "You're out of bounds." << '\n'; exit(1);}
}

const complex &complex::operator=(const complex & eq) {
    if (this == &eq) {
        return *this;
    }
    delete[] vec;
    vec = new double[size];
    for (int i = 0; i < size; ++ i) {
        vec[i] = eq.vec[i];
    }
    //DEBUG: operator =" << endl;
    return *this;
}

void complex::Print() {
    //prints the real component
    cout << vec[0];
    //prints the imaginary component
    if (vec[1] < 0) { cout << " - " << abs(vec[1]) << "i";}
    else { cout << " + " << vec[1] << "i";}
    //cout << "DEBUG: Print()" << endl;
    return;
}

double complex::Length() {
    //gives the magnitude of the vector
    double magnitude = 0;
    for (int i = 0; i < size; ++ i) {
        magnitude += pow(vec[i],2);
    }
    //cout << "DEBUG: Length()" << endl;
    return sqrt(magnitude);
}
