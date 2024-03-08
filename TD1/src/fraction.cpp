#include <iostream>
#include "fraction.hpp"
#include "utils.hpp"

Fraction operator+(Fraction f1, Fraction f2){
    Fraction result;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    return simplify(result);
}

Fraction operator-(Fraction f1, Fraction f2){
    Fraction result;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    return simplify(result);
}

Fraction operator*(Fraction f1, Fraction f2){
    Fraction result;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator * f2.numerator;
    return simplify(result);
}

Fraction operator/(Fraction f1, Fraction f2){
    Fraction result;
    result.denominator = f1.denominator * f2.numerator;
    result.numerator = f1.numerator * f2.denominator;
    return simplify(result);
}

std::ostream& operator<<(std::ostream os, Fraction const& f){
    std::cout << "Fraction : " << f.numerator << " / " << f.denominator << std::endl;
}

bool operator==(Fraction const& f1, Fraction const& f2){
    return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    return !(f1 == f2);
}

Fraction operator<(Fraction f1, Fraction f2){
    return f1 < f2;
}

auto operator<=>(Fraction const& f) const = default;


Fraction& operator +=(Fraction const& f){
    denominator *= f.denominator;
    numerator = f.numerator * denominator + numerator * f.denominator;
}

Fraction& operator -=(Fraction const& f){
    denominator *= f.denominator;
    numerator = f.numerator * denominator - numerator * f.denominator;
}

Fraction& operator *=(Fraction const& f){
    denominator *= f.denominator;
    numerator *= f.numerator;
}

Fraction& operator /=(Fraction const& f){
    denominator *= f.numerator;
    numerator *= f.denominator;
}