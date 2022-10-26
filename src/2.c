#include <stdio.h>
#include <string.h>


long double pow2(long double base, unsigned int exponent) {
    if (exponent == 0) {
        return 1;
    } 
    long double returnedValue = base;
    unsigned int remainingExponent = exponent - 1;
    while (remainingExponent > 0) {
        returnedValue = returnedValue * base;
        remainingExponent = remainingExponent - 1;
    }
    return returnedValue;
}

int main() {
    printf("2^3 is %Lf", pow2(2, 2));
}
