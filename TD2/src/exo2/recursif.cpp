#include <vector>
#include <iostream>
#include "function.hpp"
#include "utils.hpp"


int main(){
    std::vector<float> vec1 {2,9,6,7,2,5};
    quick_sort(vec1);
    display(vec1);
    std::cout <<"Voici le tableau trié :" << std::endl;
}
