#include <iostream>
#include <vector>

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

void dfs(std::vector<std::vector<int>> &field, int x, int y, int m, int n){
    field[y][x] = 0;

    for(int i = 0; i < 4; i++){
        int nx = x + mx[i];
        int ny = y + my[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n){
            continue;
        }

        if(field[ny][nx]){
            dfs(field, nx, ny, m, n);
        }
    }

    return;
}

int main(){
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++){
        int m, n, k;
        std:: cin >> m >> n >> k;

        std::vector<std::vector<int>> field(n, std::vector<int>(m, 0));
        for(int i = 0; i < k; i++){
            int x, y;
            std::cin >> x >> y;
            field[y][x] = 1;
        }

        int earthworm_count = 0;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                if(field[y][x]){
                    earthworm_count++;
                    dfs(field, x, y, m, n);
                }
            }
        }
        
        std::cout << earthworm_count << std::endl;
    }

    return 0;
}