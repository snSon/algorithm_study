#include <iostream>
#include <vector>

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

int brute_force(std::vector<std::vector<char>> &board, std::vector<char> &result, std::vector<bool> &visited, int r, int c, int x, int y){

    int sum = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + mx[i];
        int ny = y + my[i];

        if(nx < 0 || nx >= c || ny < 0 || ny >= r){
            continue;
        }

        char next_alphabet = board[ny][nx];
        if(!visited[next_alphabet - 'A']){
            visited[next_alphabet - 'A'] = true;
            result.push_back(next_alphabet);
            int curr_result = brute_force(board, result, visited, r, c, nx, ny) + 1;
            if(sum < curr_result){
                sum = curr_result;
            }
            visited[next_alphabet - 'A'] = false;
            result.pop_back();
        }
    }

    return sum;
}

int main(){
    int r, c;
    std::cin >> r >> c;

    std::vector<std::vector<char>> board(r, std::vector<char>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            std::cin >> board[i][j];
        }
    }

    std::vector<char> result;
    std::vector<bool> visited('Z' - 'A' + 1, false);
    visited[board[0][0] - 'A'] = true;
    result.push_back(board[0][0]);
    std::cout << brute_force(board, result, visited, r, c, 0, 0) << std::endl;

    return 0;
}