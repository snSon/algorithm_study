#include <iostream>
#include <vector>
#include <cmath>

int binary_search(std::vector<int> trees, int n, unsigned int m, int min, int max){
    if(min > max){
        return max;
    }

    int mid = (min + max) / 2;
    // std::cout << mid << std::endl;

    unsigned long long cut_amount = 0;
    for(int t : trees){
        cut_amount = (t > mid) ? cut_amount + t - mid : cut_amount;
    }

    if(cut_amount < m){
        return binary_search(trees, n, m, min, mid - 1);
    }
    else{
        return binary_search(trees, n, m, mid + 1, max);
    }
    

    return -1;
}

int main(){
    int n;
    unsigned int m;
    std::cin >> n >> m;

    int max_tree = 0;
    std::vector<int> trees(n);
    for(int i = 0; i < n; i++){
        std::cin >> trees[i];
        max_tree = std::max(max_tree, trees[i]);
    }

    int min_cut = binary_search(trees, n, m, 0, max_tree);

    std::cout << min_cut << std::endl;

    return 0;
}