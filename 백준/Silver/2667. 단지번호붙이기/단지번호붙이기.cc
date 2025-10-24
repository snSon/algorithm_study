#include <iostream>
#include <vector>
#include <algorithm>

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

int dfs(std::vector<std::vector<int>> &input, std::vector<std::vector<bool>> &visited,
        int n, int y, int x){
    int unit = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + mx[i];
        int ny = y + my[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n){
            continue;
        }

        if(!visited[ny][nx] && input[ny][nx] == 1){
            visited[ny][nx] = true;
            unit += dfs(input, visited, n, ny, nx);
        }
    }

    return unit;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> input(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        std::string num;
        std::cin >> num;
        for(int j = 0; j < n; j++){
            input[i][j] = num[j] - '0';
        }
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    std::vector<int> units;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && input[i][j] == 1){
                visited[i][j] = true;
                int unit = dfs(input, visited, n, i, j);
                units.push_back(unit);
            }
        }
    }

    sort(units.begin(), units.end());
    std::cout << units.size() << std::endl;
    for(int u : units){
        std::cout << u << "\n";
    }
    
    return 0;
}