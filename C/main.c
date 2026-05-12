#include <stdio.h>
#include "geometry.h"

int main() {
    Complex c;
    c.real = 3;
    c.imag = 4;

    printf("Magnitude = %.2lf\n", magnitude(c));
    printf("Phase Angle = %.2lf radians\n", phase(c));

    return 0;
}
