#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main(){
    int n, e;
    std::cin >> n >> e;

    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
    for(int i = 0; i < e; i++){
        int s, e, w;
        std::cin >> s >> e >> w;

        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    std::vector<int> start_points = {1, v1, v2};

    std::vector<std::vector<int>> dist(3, std::vector<int>(n + 1, INT_MAX));
    for(int i = 0; i < 3; i++){
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.push({0, start_points[i]});
        dist[i][start_points[i]] = 0;

        while(!pq.empty()){
            auto [curr_d, curr_p] = pq.top();
            pq.pop();

            if(curr_d > dist[i][curr_p]){
                continue;
            }

            for(auto &edge : graph[curr_p]){
                if(curr_d + edge.second < dist[i][edge.first]){
                    dist[i][edge.first] = curr_d + edge.second;
                    pq.push({dist[i][edge.first], edge.first});
                }
            }
        }
    }

    if((dist[0][v1] == INT_MAX || dist[1][v2] == INT_MAX || dist[2][n] == INT_MAX) 
        && (dist[0][v2] == INT_MAX || dist[2][v1] == INT_MAX || dist[1][n] == INT_MAX)){
            std::cout << "-1\n";
    }
    else{
      std::cout << std::min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]) << std::endl;
    }


    return 0;
}