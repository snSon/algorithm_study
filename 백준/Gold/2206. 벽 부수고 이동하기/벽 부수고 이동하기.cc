#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Node{
    int dist;
    int x, y;
    int is_distroyed = 0;
};

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<bool>> map(n, std::vector<bool>(m));
    for(int i = 0; i < n; i++){
        std::string line;
        std::cin >> line;
        for(int j = 0; j < m; j++){
            map[i][j] = line[j] - '0';
        }
    }

    std::queue<Node> q;
    q.push({1, 0, 0, 0});

    int mx[4] = {1, -1, 0, 0};
    int my[4] = {0, 0, 1, -1};

    std::vector<std::vector<int>> dist(n, std::vector<int>(m, INT_MAX));
    std::vector<std::vector<int>> wall_dist(n, std::vector<int>(m, INT_MAX));
    dist[0][0] = 1;

    int is_exist = 0;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();

        if(curr.x == m - 1 && curr.y == n - 1){
            is_exist = 1;
            break;
        }

        for(int i = 0; i < 4; i++){

            int nx = curr.x + mx[i];
            int ny = curr.y + my[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                continue;
            }

            if(curr.is_distroyed){
                if(map[ny][nx]){
                    continue;
                }
                else{
                    if(curr.dist + 1 < wall_dist[ny][nx]){
                        wall_dist[ny][nx] = curr.dist + 1;
                        q.push({wall_dist[ny][nx], nx, ny, curr.is_distroyed});
                    }
                }
            }
            else{
                if(map[ny][nx]){
                    if(curr.dist + 1 < wall_dist[ny][nx]){
                        wall_dist[ny][nx] = curr.dist + 1;
                        q.push({wall_dist[ny][nx], nx, ny, 1});
                    }
                }
                else{
                    if(curr.dist + 1 < dist[ny][nx]){
                        dist[ny][nx] = curr.dist + 1;
                        q.push({dist[ny][nx], nx, ny, curr.is_distroyed});
                    }
                }
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         std::cout << dist[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         std::cout << wall_dist[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    if(is_exist){
        std::cout << std::min(dist[n - 1][m - 1], wall_dist[n - 1][m - 1]) << std::endl;
    }
    else{
        std::cout << -1 << std::endl;
    }

    return 0;
}