#include <iostream>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;

    std::vector<int> coins(n);
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }

    int result = 0;
    for(int i = n - 1; i >= 0; i--){
        result += k / coins[i];
        k %= coins[i];
    }

    std::cout << result << '\n';

    return 0;
}