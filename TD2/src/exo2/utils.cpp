#include <iostream>
#include "utils.hpp"

void display(std::vector<float> &vec)
{
    std::cout << "[";
    for (int i{0}; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]";
}
