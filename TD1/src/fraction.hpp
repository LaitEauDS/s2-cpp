#include <iostream>

struct Fraction{
    unsigned int numerator{0};
    unsigned int denominator{1};
    void display();
};

    Fraction add(Fraction f1, Fraction f2);
    Fraction sub(Fraction f1, Fraction f2);
    Fraction mul(Fraction f1, Fraction f2);
    Fraction div(Fraction f1, Fraction f2);