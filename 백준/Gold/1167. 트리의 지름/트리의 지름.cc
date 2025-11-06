#include <iostream>
#include <vector>
#include <queue>

std::pair<int, int> dfs(int start, std::vector<std::vector<std::pair<int, int>>> &graph, int n){
    std::queue<int> q;
    std::vector<int> dist(n + 1, -1);

    dist[start] = 0;
    q.push(start);

    int max_dist = 0;
    int max_idx = start;
    while(!q.empty()){
        int curr_v = q.front();
        q.pop();

        for(auto [next, w] : graph[curr_v]){
            if(dist[next] == -1){
                dist[next] = dist[curr_v] + w;
                q.push(next);

                if(dist[next] > dist[max_idx]){
                    max_dist = dist[next];
                    max_idx = next;
                }
            }
        }
    }

    return {max_idx, max_dist};
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int vertex_num;
    std::cin >> vertex_num;

    std::vector<std::vector<std::pair<int, int>>> graph(vertex_num + 1);

    for(int i = 1; i <= vertex_num; i++){
        int v;
        std::cin >> v;
        while(true){
            int next, w;

            std::cin >> next;
            if(next == -1){
                break;
            }
            std::cin >> w;

            graph[v].push_back({next, w});
        }
    }

    auto [max_v_1, max_d_1] = dfs(1, graph, vertex_num);
    auto [max_v_2, max_d_2] = dfs(max_v_1, graph, vertex_num);

    std::cout << max_d_2 << std::endl;

    return 0;
}