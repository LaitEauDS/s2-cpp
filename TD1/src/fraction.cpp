#include <iostream>
#include "fraction.hpp"
#include "utils.hpp"

// Fraction operator+(Fraction f1, Fraction f2){
//     Fraction result;
//     result.denominator = f1.denominator * f2.denominator;
//     result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
//     return simplify(result);
// }

// Fraction operator-(Fraction f1, Fraction f2){
//     Fraction result;
//     result.denominator = f1.denominator * f2.denominator;
//     result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
//     return simplify(result);
// }

// Fraction operator*(Fraction f1, Fraction f2){
//     Fraction result;
//     result.denominator = f1.denominator * f2.denominator;
//     result.numerator = f1.numerator * f2.numerator;
//     return simplify(result);
// }

// Fraction operator/(Fraction f1, Fraction f2){
//     Fraction result;
//     result.denominator = f1.denominator * f2.numerator;
//     result.numerator = f1.numerator * f2.denominator;
//     return simplify(result);
// }

std::ostream& operator<<(std::ostream os, Fraction const& f){
    return os << "Fraction : " << f.numerator << " / " << f.denominator << std::endl;
}

bool operator==(Fraction const& f1, Fraction const& f2){
    Fraction sf1 = simplify(f1);
    Fraction sf2 = simplify(f2);
    return sf1.numerator == sf2.numerator && sf1.denominator == sf2.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    return !(f1 == f2);
}

bool operator<(Fraction f1, Fraction f2){
    float ff1 = static_cast<float>(f1.numerator)/static_cast<float>(f1.denominator);
    float ff2 = static_cast<float>(f2.numerator)/static_cast<float>(f2.denominator);
    return ff1 < ff2;
}

bool operator>(Fraction f1, Fraction f2){
    if (f1 != f2 && !(f1< f2)){
        return f1 > f2;
    }
}

bool operator<=(Fraction f1, Fraction f2){
    if (f1 < f2 || f1==f2){
        return f1 <= f2;
    }
}

bool operator>=(Fraction f1, Fraction f2){
    if (f1 > f2 || f1==f2){
        return f1 >= f2;
    }
}

void Fraction::operator+=(const Fraction& f) {
    denominator *= f.denominator;
    numerator = numerator * f.denominator + f.numerator * denominator;
}

void Fraction::operator-=(const Fraction& f) {
    denominator *= f.denominator;
    numerator = numerator * f.denominator - f.numerator * denominator;
}

void Fraction::operator*=(const Fraction& f) {
    denominator *= f.denominator;
    numerator *= f.numerator;
}

void Fraction::operator/=(const Fraction& f) {
    denominator *= f.numerator;
    numerator *= f.denominator;
}

Fraction operator+(const Fraction& f1, const Fraction& f2) {
    Fraction result = f1;
    result += f2;
    return (simplify(result));
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
    Fraction result = f1;
    result -= f2;
    return (simplify(result));
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
    Fraction result = f1;
    result *= f2;
    return (simplify(result));
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
    Fraction result = f1;
    result /= f2;
    return (simplify(result));
}

float Fraction::to_float() const {
    return static_cast<float>(numerator) / denominator;
}

Fraction::operator float() const {
    return to_float(); 
}

