#include <stdio.h>
#include "complex.h"

int main() {

    struct Complex c1, c2, sum, product;

    printf("Enter real and imaginary part of first complex number: ");
    scanf("%d %d", &c1.real, &c1.imag);

    printf("Enter real and imaginary part of second complex number: ");
    scanf("%d %d", &c2.real, &c2.imag);

    sum = add_complex(c1, c2);
    product = mul_complex(c1, c2);

    printf("\nAddition = %d + %di\n", sum.real, sum.imag);

    printf("Multiplication = %d + %di\n",
           product.real,
           product.imag);

    return 0;
}
