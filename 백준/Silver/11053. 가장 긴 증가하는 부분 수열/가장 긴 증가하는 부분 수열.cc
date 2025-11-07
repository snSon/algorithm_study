#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> input(n);
    for(int i = 0; i < n; i++){
        std::cin >> input[i];
    }

    std::vector<int> dp_arr(n, 0);
    dp_arr[0] = 1;
    for(int i = 1; i < n; i++){
        int max = 0;
        for(int j = 0; j < i; j++){
            if(input[j] < input[i]){
                max = std::max(dp_arr[j], max);
            }
        }
        dp_arr[i] = max + 1;
    }

    // for(int i = 0; i <= n; i++){
    //     std::cout << dp_arr[i] << " ";
    // }
    // std::cout << std::endl;

    int max = 0;
    for(int i = 0; i < n; i++){
        max = std::max(max, dp_arr[i]);
    }

    std::cout << max << std::endl;

    return 0;
}