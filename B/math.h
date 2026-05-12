#ifndef MATH_H
#define MATH_H

typedef struct {
    float real;
    float imag;
} Complex;

float absolute(Complex c);
float power_complex(Complex c);

#endif
