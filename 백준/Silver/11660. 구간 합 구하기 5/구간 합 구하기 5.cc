#include <iostream>
#include <vector>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> input(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> input[i][j];
        }
    }

    std::vector<std::vector<int>> dp_arr(n + 1, std::vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp_arr[i][j] = dp_arr[i][j - 1] + dp_arr[i - 1][j] - dp_arr[i - 1][j - 1] + input[i - 1][j - 1];
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= n; j++){
    //         std::cout << dp_arr[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::string output;
    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        output += (std::to_string(dp_arr[x2][y2] - dp_arr[x2][y1 - 1] - dp_arr[x1 - 1][y2] + dp_arr[x1 - 1][y1 - 1]) + '\n');
    }

    std::cout << output;

    return 0;
}