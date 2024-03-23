#include <iostream>
#include "fraction.hpp"

int main(){
    Fraction f1;
    Fraction f2;

    std::cout << "1. Veuillez entre le numérateur de la première fraction" << std::endl;
    std::cin >> f1.numerator;
    std::cout << "2. Veuillez entre le dénominateur de la première fraction" << std::endl;
    std::cin >> f1.denominator;
    std::cout << "3. Veuillez entre le numérateur de la deuxième fraction" << std::endl;
    std::cin >> f2.numerator;
    std::cout << "4. Veuillez entre le numérateur de la deuxième fraction" << std::endl;
    std::cin >> f2.denominator;

    return 0;
}