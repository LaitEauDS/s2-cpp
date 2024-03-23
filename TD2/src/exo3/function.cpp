#include <iostream>
#include "function.hpp"
#include <vector>

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot){
    float valeurPivot = vec[pivot];
    size_t indexPartition = left;

    std::swap(vec[pivot], vec[right]); //Déplace le pivot à la fin

    for (size_t i = left; i < right; i++) {
        if (vec[i] < valeurPivot) {
            std::swap(vec[i], vec[indexPartition]);
            indexPartition++;
        }
    }
    std::swap(vec[right], vec[indexPartition]); //Déplace le pivot à sa place finale
    return indexPartition;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right){
    if (left < right) {
        size_t pivot = left + (right - left) / 2;
        size_t indexPartition = quick_sort_partition(vec, left, right, pivot);

        if (indexPartition > 0)
            quick_sort(vec, left, indexPartition - 1);
        quick_sort(vec, indexPartition + 1, right);
    }
}

void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}
