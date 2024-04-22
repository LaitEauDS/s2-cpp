#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int sizeFirstWord(std::string const& str){
    auto const is_space = [](char letter){ return letter == ' '; };
    auto debut = std::find_if_not(str.begin(), str.end(), is_space); // Début du premier mot
    auto fin = std::find_if(debut, str.end(), is_space); // Fin du premier mot

    return std::distance(debut,fin);
};


std::vector<std::string> split_string(std::string const& str) {
    std::vector<std::string> result;
    auto const is_space = [](char letter) { return letter == ' '; };
    
    auto it_start = str.begin();
    while (it_start != str.end()) {
        // Début du mot
        it_start = std::find_if_not(it_start, str.end(), is_space); 
        if (it_start == str.end()) break;
        
        // Fin du mot
        auto it_end = std::find_if(it_start, str.end(), is_space);
        result.push_back(std::string(it_start, it_end)); // Ajoute le mot trouvé au vecteur
        
        it_start = it_end;
    }

    return result;
}


int main(){

    std::string text;
    std::cout << "Entrez une phrase : ";
    std::cin >> text;
    
    std::cout << "Taille du premier mot : " << sizeFirstWord(text) << std::endl;
    
    for (std::string const element : split_string(text)) {
        std::cout <<  element << std::endl;
    }

    return 0;
}