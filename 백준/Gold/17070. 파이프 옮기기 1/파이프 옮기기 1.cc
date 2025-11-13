#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> board(n, std::vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> board[i][j];
        }
    }

    std::vector<std::vector<std::vector<int>>> dp_arr(n, std::vector<std::vector<int>>(n, std::vector<int>(3, 0)));
    dp_arr[0][1][0] = 1;
    for(int i = 2; i < n; i++){
        if(board[0][i]){
            break;
        }
        dp_arr[0][i][0] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 2; j < n; j++){
            if(board[i][j]){
                continue;
            }

            if(!(board[i - 1][j] || board[i][j - 1])){
                dp_arr[i][j][2] = dp_arr[i - 1][j - 1][0] + dp_arr[i - 1][j - 1][1] + dp_arr[i - 1][j - 1][2];
            }
            if(!board[i - 1][j]){
                dp_arr[i][j][1] = dp_arr[i - 1][j][1] + dp_arr[i - 1][j][2];
            }
            if(!board[i][j - 1]){
                dp_arr[i][j][0] = dp_arr[i][j - 1][0] + dp_arr[i][j - 1][2];
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         std::cout << dp_arr[i][j][0] << dp_arr[i][j][1] << dp_arr[i][j][2] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << dp_arr[n - 1][n - 1][0] + dp_arr[n - 1][n - 1][1] + dp_arr[n - 1][n - 1][2] << '\n';

    return 0;
}