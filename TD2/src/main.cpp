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

int main() {
    std::vector<int> array {5,4,8,0,7,1,9};
    selection_sort(array);
    if (is_sorted(array)) {
        std::cout << "Le tableau est trié" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}