#include <math.h>
#include "geometry.h"

double magnitude(Complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

double phase(Complex c) {
    return atan2(c.imag, c.real);
}
