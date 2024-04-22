#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {

    // Vecteur avec nombres entiers aléatoires entre 0 et 100
    std::vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(std::rand() % 100 + 1);
    }

    // Affichage des valeurs du vecteur
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }

    
    int nombre;
    std::cout << "Entrez un nombre : ";
    std::cin >> nombre;

    // Cherche si le nombre saisie est présent dans le vecteur
    auto found = std::find(v.begin(), v.end(), nombre);
    if (found != v.end()) {
        std::cout << nombre << " est présent dans le vecteur.\n";
    } else {
        std::cout << nombre << " n'est pas présent dans le vecteur.\n";
    }


    // Nombre de fois que le nombre choisi est présent dans le vecteur
    int count = std::count(v.begin(), v.end(), nombre);
    std::cout << nombre << " est " << count << " fois dans le vecteur." << std::endl;


    // Trie le vecteur
    std::sort(v.begin(), v.end());
    std::cout << "Vecteur trié : ";
    for (int element: v) {
        std::cout << element << std::endl;
    }


    // Calcul de la somme des éléments du vecteur
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Somme des éléments du vecteur : " << sum << std::endl;


    return 0;
}
