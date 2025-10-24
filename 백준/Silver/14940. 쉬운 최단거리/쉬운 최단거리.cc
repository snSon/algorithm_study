#include <iostream>
#include <queue>
#include <vector>

struct node{
    int dist;
    int x, y;
};

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> map(n, std::vector<int>(m, 0));
    int dst_x, dst_y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> map[i][j];
            if(map[i][j] == 2){
                dst_x = j;
                dst_y = i;
            }
        }
    }

    std::vector<std::vector<int>> result(n, std::vector<int>(m, 0));
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::queue<node> q;
    q.push({0, dst_x, dst_y});
    visited[dst_y][dst_x] = true;

    int mx[4] = {1, -1, 0, 0};
    int my[4] = {0, 0, 1, -1};

    while(!q.empty()){
        node curr = q.front();
        q.pop();
        result[curr.y][curr.x] = curr.dist;
        // std::cout << curr.x << " " << curr.y << std::endl;

        for(int i = 0; i < 4; i++){
            int nx = curr.x + mx[i];
            int ny = curr.y + my[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                continue;
            }

            if(!visited[ny][nx] && map[ny][nx] != 0){
                q.push({curr.dist + 1, nx, ny});
                visited[ny][nx] = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && map[i][j]){
                result[i][j] = -1;
            }
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}