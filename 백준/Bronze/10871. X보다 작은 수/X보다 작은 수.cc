#include <iostream>
#include <vector>

int main() {
    int num,min,N ;
    std::vector<int> vec;
    
    std::cin >> num >> min;

    for (int i = 1; i <= num; i++) {
        std::cin >> N;
        vec.push_back(N);


    }
    for (auto i : vec){
        if (i < min) std::cout << i << " ";
    }


}