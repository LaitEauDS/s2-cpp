#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& str) {
    return std::equal(std::begin(str), std::begin(str) + str.size() / 2, std::rbegin(str));
}

int main() {

    std::string test1 = "kayak";
    std::string test2 = "bonjour";
    std::cout << (is_palindrome(test1) ? "Oui" : "Non") << std::endl;
    std::cout << (is_palindrome(test2) ? "Oui" : "Non") << std::endl;

    return 0;
}
