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
    
    int sum = 0;
    int wait_time = 0;
    for(int i : inputs){
        sum += (wait_time + i);
        wait_time += i;
    }

    std::cout << sum << std::endl;

    return 0;
}