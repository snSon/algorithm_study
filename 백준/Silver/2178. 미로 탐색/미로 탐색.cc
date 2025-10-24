#include <iostream>
#include <vector>
#include <queue>

struct node{
    int dist;
    int x, y;
};

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> miro(n, std::vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        std::string num;
        std::cin >> num; 
        for(int j = 0; j < m; j++){
            miro[i][j] = num[j] - '0';
        }
    }

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::queue<node> q;
    q.push({1, 0, 0});
    visited[0][0] = true;
    
    int mx[4] = {1, -1, 0, 0};
    int my[4] = {0, 0, 1, -1};
    while(!q.empty()){
        node curr = q.front();
        q.pop();

        //std::cout << curr.x << " " << curr.y << std::endl;

        if(curr.y == n - 1 && curr.x == m - 1){
            std::cout << curr.dist << std::endl;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx = curr.x + mx[i];
            int ny = curr.y + my[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                continue;
            }

            if(!visited[ny][nx] && miro[ny][nx]){
                q.push({curr.dist + 1, nx, ny});
                visited[ny][nx] = true;
            }
        }
    }

    return 0;
}