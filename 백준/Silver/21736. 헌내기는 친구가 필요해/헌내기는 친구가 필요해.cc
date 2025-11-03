#include <iostream>
#include <vector>

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

int dfs(std::vector<std::vector<char>> &campus, std::vector<std::vector<bool>> &visited, int x, int y, int n, int m){
    int result = (campus[y][x] == 'P') ? 1 : 0;

    // std::cout << "loop\n";

    for(int i = 0; i < 4; i++){
        int nx = x + mx[i];
        int ny = y + my[i];
        
        if(nx < 0 || nx >= m || ny < 0 || ny >= n){
            continue;
        }

        if(!visited[ny][nx] && campus[ny][nx] != 'X'){
            visited[ny][nx] = true;
            result += dfs(campus, visited, nx, ny, n, m);
        }
    }

    return result;
}

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> campus(n, std::vector<char>(m));
    int start_x, start_y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                start_x = j;
                start_y = i;
            }
        }
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    visited[start_y][start_x] = true;

    int result = dfs(campus, visited, start_x, start_y, n, m);
    if(result){
        std::cout << result << "\n";
    }
    else{
        std::cout << "TT" << "\n";
    }

    return 0;
}