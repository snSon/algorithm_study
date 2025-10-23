#include <iostream>
#include <vector>
#include <cmath>

unsigned int binary_search(std::vector<unsigned int> &cables, unsigned int min, unsigned int max, int n){
    if(min > max){
        return max;
    }

    unsigned int mid = (min + max)/2;
    long long pieces = 0;
    for(int c : cables){
        pieces += c/mid;
    }

    if(pieces >= n){
        return binary_search(cables, mid + 1, max, n);
    }
    else{
        return binary_search(cables, min, mid - 1, n);
    }

    return -1;
}


int main(){
    int k, n;
    std::cin >> k >> n;

    std::vector<unsigned int> cables(k);
    unsigned int max_len = 0;
    for(int i = 0; i < k; i++){
        std::cin >> cables[i];
        max_len = std::max(max_len, cables[i]);
    }

    unsigned int result = binary_search(cables, 1, max_len, n);

    std::cout << result << std::endl;

    return 0;
}