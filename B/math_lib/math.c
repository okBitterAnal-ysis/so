/*
Commands:
gcc -fPIC -shared -o libmath.so math.c -lm
gcc test.c -L. -lmath -Wl,-rpath,. -o test -lm
./test
*/

#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

double complex_abs(Complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

double complex_power(Complex c) {
    return (c.real * c.real) + (c.imag * c.imag);
}
