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

        int skip = 0;
        int up = stickers[0][0];
        int down = stickers[1][0];
        for(int k = 1; k < n; k++){
            int curr_skip = std::max(std::max(skip, up),  down);
            int curr_up = std::max(skip, down) + stickers[0][k];
            int curr_down = std::max(skip, up) + stickers[1][k];

            skip = curr_skip;
            up = curr_up;
            down = curr_down;
        }

        // for(int j = 0; j < 2; j++){
        //     for(int k = 0; k <= n; k++){
        //         std::cout << dp_arr[j][k] << " ";
        //     }
        //     std::cout << std::endl;
        // }

        std::cout << std::max(std::max(skip, up), down) << std::endl;
    }

    return 0;
}