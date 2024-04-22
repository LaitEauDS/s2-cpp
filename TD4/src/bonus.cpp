#include <iostream>
#include <vector>
#include <numeric>

int sommeCarres(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0,
        [](int a, int b) { return a + b * b; });
}

int produitElementsPairs(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 1,
        [](int a, int b) { return (b % 2 == 0) ? a * b : a; });
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << "Somme des carrés : " << sommeCarres(v) << std::endl;
    std::cout << "Produits des éléments pairs: " << produitElementsPairs(v) << std::endl;
    return 0;
}
