#include <stdio.h>

struct Complex {
    int real;
    int imag;
};

struct Complex add_complex(struct Complex a, struct Complex b) {
    struct Complex result;

    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;

    return result;
}

struct Complex mul_complex(struct Complex a, struct Complex b) {
    struct Complex result;

    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);

    return result;
}
