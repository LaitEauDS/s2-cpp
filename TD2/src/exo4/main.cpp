#include <iostream>
#include <vector>

int search(const std::vector<int> &vec, int value) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (vec[middle] == value) {
            return middle; // La valeur a été trouvée, retourne son indice
        } else if (vec[middle] < value) {
            left = middle + 1; // Recherche dans la moitié droite
        } else {
            right = middle - 1; // Recherche dans la moitié gauche
        }
    }

    return -1; // La valeur n'a pas été trouvée
}

int main() {
    std::vector<std::vector<int>> test = {
        {1, 2, 2, 3, 4, 8, 12}, // Valeur recherchée: 8
        {1, 2, 3, 3, 6, 14, 12, 15}, // Valeur recherchée: 15
        {2, 2, 3, 4, 5, 8, 12, 15, 16}, // Valeur recherchée: 16
        {5, 6, 7, 8, 9, 10, 11, 12, 13}, // Valeur recherchée: 6
        {1, 2, 3, 4, 5, 6, 7, 8, 9} // Valeur recherchée: 10
    };

    for (const auto &testC : test) {
        int searchValue= testC.back(); // La valeur recherchée est la dernière dans le vecteur
        test.pop_back(); // Retire la valeur recherchée du vecteur pour la recherche
        int result = search(testC, searchValue);
        
        std::cout << "Valeur recherchée dans le tableau [";
        for (size_t i = 0; i < test.size(); ++i) {
            std::cout << testC[i];
            if (i != test.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]: " << searchValue << ", Indice trouvé: " << result << std::endl;
    }

    return 0;
}
