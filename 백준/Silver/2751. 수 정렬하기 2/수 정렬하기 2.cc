#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    
    std::vector<int> inputs(n);
    for(int i = 0; i < n; i++){
        std::cin >> inputs[i];
    }
    
    sort(inputs.begin(), inputs.end());
    
    for(int i = 0; i < n; i++){
        std::cout << inputs[i] << '\n';
    }
    
    return 0;
}