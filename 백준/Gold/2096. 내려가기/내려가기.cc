#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;


    int max_dp[2][3] = {{0, 0, 0}, {0, 0, 0}};
    int min_dp[2][3] = {{0, 0, 0}, {0, 0, 0}};

    for(int i = 0; i < n; i++){
        for(int i = 0; i < 3; i++){
            max_dp[0][i] = max_dp[1][i];
            min_dp[0][i] = min_dp[1][i];
            
            int num;
            std::cin >> num;
            max_dp[1][i] = num;
            min_dp[1][i] = num;
        }
        
        max_dp[1][0] = max_dp[1][0] + std::max(max_dp[0][0], max_dp[0][1]);
        max_dp[1][1] = max_dp[1][1] + std::max(std::max(max_dp[0][0], max_dp[0][1]), max_dp[0][2]);
        max_dp[1][2] = max_dp[1][2] + std::max(max_dp[0][1], max_dp[0][2]);

        min_dp[1][0] = min_dp[1][0] + std::min(min_dp[0][0], min_dp[0][1]);
        min_dp[1][1] = min_dp[1][1] + std::min(std::min(min_dp[0][0], min_dp[0][1]), min_dp[0][2]);
        min_dp[1][2] = min_dp[1][2] + std::min(min_dp[0][1], min_dp[0][2]);
    }

    std::cout << std::max(std::max(max_dp[1][0], max_dp[1][1]), max_dp[1][2])
        << " " << std::min(std::min(min_dp[1][0], min_dp[1][1]), min_dp[1][2]) << std::endl;

    return 0;
}