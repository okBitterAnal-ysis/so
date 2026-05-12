#include <stdio.h>
#include "complex.h"

int main() {
    Complex a = {2, 3};
    Complex b = {4, 5};

    Complex sum = add_complex(a, b);
    Complex product = mul_complex(a, b);

    printf("Addition = %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Multiplication = %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}
