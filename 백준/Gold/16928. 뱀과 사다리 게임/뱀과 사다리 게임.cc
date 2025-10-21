#include <iostream>
#include <vector>
#include <queue>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> ladders(n);
    std::vector<std::pair<int, int>> snakes(m);

    for(int i = 0; i < n; i++){
        std::cin >> ladders[i].first >> ladders[i].second;
    }
    for(int i = 0; i < m; i++){
        std::cin >> snakes[i].first >> snakes[i].second;
    }

    std::queue<std::pair<int, int>> q;
    std::vector<bool> visited(101, false);
    q.push({0, 1});
    visited[1] = true;

    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int count = curr.first, idx = curr.second;

        if(idx == 100){
            std::cout << count << std::endl;
            return 0;
        }

        for(int move = 1; move <= 6; move++){
            int next = idx + move;
            for(int i = 0; i < n; i++){
                if(next == ladders[i].first){
                    next = ladders[i].second;
                    break;
                }
            }
            for(int i = 0; i < m; i++){
                if(next == snakes[i].first){
                    next = snakes[i].second;
                }
            }
            if(!visited[next] && idx <= 100){
                q.push({count + 1, next});
                visited[next] = true;
            }
        }
    }

    return 0;
}