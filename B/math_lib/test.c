/*
Commands:
gcc -fPIC -shared -o libmath.so math.c -lm
gcc test.c -L. -lmath -Wl,-rpath,. -o test -lm
./test
*/

#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

double complex_abs(Complex);
double complex_power(Complex);

int main() {
    Complex c = {3, 4};

    printf("Complex Number: %.1f + %.1fi\n", c.real, c.imag);
    printf("Magnitude = %.2f\n", complex_abs(c));
    printf("Power = %.2f\n", complex_power(c));

    return 0;
}
