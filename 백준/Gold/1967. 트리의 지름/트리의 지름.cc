#include <iostream>
#include <vector>
#include <queue>

std::pair<int, int> bfs(int start, std::vector<std::vector<std::pair<int, int>>> &tree, int n){
    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;
    dist[start] = 0;
    q.push(start);

    int max_idx = start;
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto [next, next_d] : tree[curr]){
            if(dist[next] == -1){
                dist[next] = next_d + dist[curr];
                q.push(next);
                if(dist[next] > dist[max_idx]){
                    max_idx = next;
                }
            }
        }
    }


    return {max_idx, dist[max_idx]};
}

int main(){
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> tree(n + 1);
    for(int i = 0; i < n - 1; i++){
        int p, c, w;
        std::cin >> p >> c >> w;
        tree[p].push_back({c, w});
        tree[c].push_back({p, w});
    }

    auto [v1_idx, v1_d] = bfs(1, tree, n);
    auto [v2_idx, v2_d] = bfs(v1_idx, tree, n);

    std::cout << v2_d << std::endl;

    return 0;
}