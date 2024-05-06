#include <iostream>
#include <vector>
#include <string>

size_t folding_string_hash(std::string const& s, size_t max){
    size_t hash_value = 0;
    for (char c : s) {
        hash_value += static_cast<unsigned char>(c);
    }
    return hash_value % max;
};

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash_value = 0;
    size_t index = 1;  // Commence à 1 pour différencier les positions initiales
    for (char c : s) {
        hash_value += index++ * static_cast<unsigned char>(c);
    }
    return hash_value % max;
};

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash_value = 0;
    size_t power = 1;  // p^0 est 1
    for (char c : s) {
        hash_value = (hash_value + static_cast<unsigned char>(c) * power) % m;
        power = (power * p) % m;
    }
    return hash_value;
};
