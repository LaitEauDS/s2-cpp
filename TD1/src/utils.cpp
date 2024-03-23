#include <iostream>
#include "utils.hpp"

int gcd(int a, int b){
    while (b != 0){
        int temporary_variable = b;
        b = a % b;
        a = temporary_variable;
    }
    return a;
}

Fraction simplify(Fraction fraction){
    Fraction result;
    int pgcd = gcd(fraction.numerator, fraction.denominator);
    result.denominator = fraction.denominator / pgcd;
    result.numerator = fraction.numerator / pgcd;
    return result;
}
