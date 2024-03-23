#pragma once 

#include <iostream>

struct Fraction{
    unsigned int numerator{};
    unsigned int denominator{};
    void operator+=(const Fraction& f);
    void operator-=(const Fraction& f);
    void operator*=(const Fraction& f);
    void operator/=(const Fraction& f);
    float to_float() const;
    operator float() const;
};

// Fraction add(Fraction f1, Fraction f2);
// Fraction sub(Fraction f1, Fraction f2);
// Fraction mul(Fraction f1, Fraction f2);
// Fraction div(Fraction f1, Fraction f2);

Fraction operator+(Fraction f1, const Fraction& f2);
Fraction operator-(Fraction f1, const Fraction& f2);
Fraction operator*(Fraction f1, const Fraction& f2);
Fraction operator/(Fraction f1, const Fraction& f2);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction f1, Fraction f2);
bool operator>(Fraction f1, Fraction f2);
bool operator<=(Fraction f1, Fraction f2);
bool operator>=(Fraction f1, Fraction f2);
