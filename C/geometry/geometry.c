/*
Commands for Static Library:
gcc -c geometry.c -o geometry.o
ar rcs libgeometry.a geometry.o
gcc main.c -L. -lgeometry -o static_test -lm
./static_test

Commands for Dynamic Library:
gcc -fPIC -shared -o libgeometry.so geometry.c -lm
gcc main.c -L. -lgeometry -Wl,-rpath,. -o dynamic_test -lm
./dynamic_test
*/

#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

double magnitude(Complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

double phase(Complex c) {
    return atan2(c.imag, c.real);
}
