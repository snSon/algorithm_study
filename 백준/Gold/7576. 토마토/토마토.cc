#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

int main(){
    int m, n;
    std::cin >> m >> n;
    
    std::vector<std::vector<int>> box(n, std::vector<int>(m, 0));
    for(int y = 0; y < n; y++)
        for(int x = 0; x < m; x++)
            std::cin >> box[y][x];
    
    std::queue<std::pair<int, int>> q;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(box[y][x] == 1)
                q.push({y, x});
        }
    }

    int mx[4] = {1, -1, 0, 0};
    int my[4] = {0, 0, 1, -1};
    while(!q.empty()){
        std::pair<int, int> curr = q.front();
        q.pop();

        int y = curr.first, x = curr.second;

        for(int i = 0; i < 4; i++){
            int nx = x + mx[i], ny = y + my[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if(box[ny][nx] == 0){
                box[ny][nx] = box[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    int max_day = 0;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(box[y][x] == 0){
                std::cout << -1 << std::endl;
                return 0;
            }
            max_day = std::max(max_day, box[y][x]);
        }
    }

    std::cout << (max_day == 1 ? 0 : max_day - 1) << std::endl;

    return 0;
}