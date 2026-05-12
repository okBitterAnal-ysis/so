#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    double real;
    double imag;
} Complex;

double magnitude(Complex c);
double phase(Complex c);

#endif
