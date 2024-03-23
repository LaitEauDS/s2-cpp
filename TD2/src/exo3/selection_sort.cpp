#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

void selection_sort(std::vector<int> &vec){
    int sub {0};
    while(!is_sorted(vec)){
        for(int i = 1; i < vec.size()-sub; i++){
            if(vec[i] < vec[i-1]){
                int temp = vec[i];
                vec[i] = vec[i-1];
                vec[i-1] = temp;
            }
        }
        sub++;
    }
}
