#include <stdio.h>
#include "math.h"

int main() {

    Complex c;

    c.real = 3;
    c.imag = 4;

    printf("Magnitude = %.2f\n", absolute(c));
    printf("Power = %.2f\n", power_complex(c));

    return 0;
}
