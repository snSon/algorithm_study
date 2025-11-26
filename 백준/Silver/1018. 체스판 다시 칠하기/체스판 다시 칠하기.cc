#include <iostream>
#include <vector>
#include <climits>

int brute_force(std::vector<std::vector<bool>> &board, int x, int y, bool first){
    int result = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0 && board[x + i][y + j] != first){
                result++;
            }
            else if((i + j) % 2 && board[x + i][y + j] == first){
                result++;
            }
        }
    }

    return result;
}

int main(){
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<bool>> board(n, std::vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            std::cin >> c;
            if(c == 'B'){
                board[i][j] = true;
            }
        }
    }

    int min = INT_MAX;
    for(int i = 0; i <= n - 8; i++){
        for(int j = 0; j <= m - 8; j++){
            min = std::min(min, brute_force(board, i, j, true));
            min = std::min(min, brute_force(board, i, j, false));
        }
    }

    std::cout << min << '\n';

    return 0;
}