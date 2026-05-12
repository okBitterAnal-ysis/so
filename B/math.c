#include <math.h>
#include "math.h"

float absolute(Complex c) {
    return sqrt(c.real*c.real + c.imag*c.imag);
}

float power_complex(Complex c) {
    return c.real*c.real + c.imag*c.imag;
}
