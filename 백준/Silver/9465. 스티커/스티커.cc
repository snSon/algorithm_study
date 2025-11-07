#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;

        std::vector<std::vector<int>> stickers(2, std::vector<int>(n));
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < n; k++){
                std::cin >> stickers[j][k];
            }
        }

        std::vector<std::vector<int>> dp_arr(2, std::vector<int>(n + 1, 0));
        dp_arr[0][1] = stickers[0][0];
        dp_arr[1][1] = stickers[1][0];
        for(int k = 2; k <= n; k++){
            dp_arr[0][k] = std::max(std::max(dp_arr[0][k - 2], dp_arr[1][k - 1]), dp_arr[1][k - 2]) + stickers[0][k - 1];
            dp_arr[1][k] = std::max(std::max(dp_arr[1][k - 2], dp_arr[0][k - 1]), dp_arr[0][k - 2]) + stickers[1][k - 1];
        }

        // for(int j = 0; j < 2; j++){
        //     for(int k = 0; k <= n; k++){
        //         std::cout << dp_arr[j][k] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        std::cout << std::max(dp_arr[1][n], dp_arr[0][n]) << std::endl;
    }

    return 0;
}