#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"
#include "selection_sort.cpp"
#include "function.hpp"
#include "utils.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}



int main()
{
    size_t vectorSize = 10000; // Taille du vecteur aléatoire
    std::vector<int> randomVector = generate_random_vector(vectorSize);
    {
        ScopedTimer timer("Selection Sort");
        selection_sort(randomVector);
        if (is_sorted(randomVector)) {
            std::cout << "Le tableau est trié" << std::endl;
        } else {
            std::cout << "Le tableau n'est pas trié" << std::endl;
        }
    }
    {
        ScopedTimer timer("Quick Sort");
        quick_sort(randomVector);
    }
    {
        ScopedTimer timer("Quick Sort");
        std::sort(randomVector.begin(), randomVector.end());
    }
    return 0;
}

// Le programme nous permet d'avoir les temps d'éxecution de chaque algorithme de tri.
// On peut ensuite les comparer ces temps pour voir quelle méthode est la plus efficace.
// Ce qui nous a permis de voir que les algorithmes sont relativement tous autant rapide pour ce tableau.
// Cependant, lors de plus gros projets, certains tris sont plus intéressants comme la récursive qui est plus efficace sur de grands tableaux.

