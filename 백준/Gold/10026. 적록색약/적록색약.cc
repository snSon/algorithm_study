#include <iostream>
#include <vector>

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};
void dfs(std::vector<std::vector<char>> &paints, 
         std::vector<std::vector<bool>> &visited,
         char color, int x, int y, int n){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + mx[i], ny = y + my[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n){
            continue;
        }

        if(!visited[nx][ny] && paints[nx][ny] == color){
            dfs(paints, visited, color, nx, ny, n);
        }
    }

    return;
}
int main(){
    int n;
    std::cin >> n;

    std::vector<std::vector<char>> paints(n, std::vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> paints[i][j];
        }
    }

    int normal_section = 0;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                normal_section++;
                dfs(paints, visited, paints[i][j], i, j, n);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(paints[i][j] == 'G'){
                paints[i][j] = 'R';
            }
        }
    }

    visited.clear();
    visited.assign(n, std::vector<bool>(n, false));
    int stranger_section = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                stranger_section++;
                dfs(paints, visited, paints[i][j], i, j, n);
            }
        }
    }

    std::cout << normal_section << " " << stranger_section << std::endl;

    return 0;
}