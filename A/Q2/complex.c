/*
Commands:
gcc -c complex.c -o complex.o
ar rcs libcomplex.a complex.o
gcc test.c -L. -lcomplex -o test
./test
*/

#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex add_complex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex mul_complex(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}
