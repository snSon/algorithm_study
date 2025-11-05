#include <iostream>
#include <vector>
#include <climits>
#include <queue>

int main(){
    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int s, e, t;
        std::cin >> s >> e >> t;

        graph[s].push_back({e, t});
    }

    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, INT_MAX));
    for(int i = 1; i <= n; i++){
        std::priority_queue<std::pair<int, int> ,std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push({0, i});
        dist[i][i] = 0;

        while(!pq.empty()){
            auto [curr_time, curr_point] = pq.top();
            pq.pop();
            if(curr_time > dist[i][curr_point]){
                continue;
            }

            for(auto &edge : graph[curr_point]){
                if(curr_time + edge.second < dist[i][edge.first]){
                    dist[i][edge.first] = curr_time + edge.second;
                    pq.push({dist[i][edge.first], edge.first});
                }
            }
        }
    }

    int max_time = -1;
    for(int i = 1; i <= n; i++){
        if((dist[i][x] != INT_MAX && dist[x][i] != INT_MAX) && (dist[i][x] + dist[x][i] > max_time)){
            max_time = dist[i][x] + dist[x][i];
        }
    }

    std::cout << max_time << std::endl;

    return 0;
}