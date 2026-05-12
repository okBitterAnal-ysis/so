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

#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

double magnitude(Complex);
double phase(Complex);

int main() {
    Complex c = {3, 4};

    printf("Magnitude = %.2f\n", magnitude(c));
    printf("Phase Angle = %.2f radians\n", phase(c));

    return 0;
}
