#include <iostream>
#include <vector>

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

int dfs(std::vector<std::vector<int>> &map, std::vector<std::vector<bool>> &visited, int x, int y, int n, int m, int depth){
    if(depth == 0){
        return map[y][x];
    }

    int max_val = -1;
    for(int i = 0; i < 4; i++){
        int nx = x + mx[i];
        int ny = y + my[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n){
            continue;
        }

        if(visited[ny][nx]){
            continue;
        }

        visited[ny][nx] = true;
        int curr_val = dfs(map, visited, nx, ny, n, m, depth - 1) + map[y][x];
        visited[ny][nx] = false;

        if(curr_val > max_val){
            max_val = curr_val;
        }
    }

    return max_val;
}

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> map(n, std::vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> map[i][j];
        }
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int result = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true;
            int tet_val = dfs(map, visited, j, i, n, m, 3);
            visited[i][j] = false;

            int tet_2_val = -1;
            for(int k = 0; k < 4; k++){
                int curr_val = map[i][j];
                for(int r = 0; r < 4; r++){
                    if(k == r){
                        continue;
                    }

                    int nx = j + mx[r];
                    int ny = i + my[r];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                        continue;
                    }

                    curr_val += map[ny][nx];
                }

                if(curr_val > tet_2_val){
                    tet_2_val = curr_val;
                }
            }

            int curr_max = std::max(tet_val, tet_2_val);
            if(curr_max > result){
                // std::cout << i << " " << j << " " << tet_val << " " << tet_2_val << std::endl;
                result = curr_max;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}