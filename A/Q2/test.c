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

Complex add_complex(Complex, Complex);
Complex mul_complex(Complex, Complex);

int main() {
    Complex c1 = {2, 3};
    Complex c2 = {4, 5};

    Complex sum = add_complex(c1, c2);
    Complex product = mul_complex(c1, c2);

    printf("Addition: %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Multiplication: %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}
