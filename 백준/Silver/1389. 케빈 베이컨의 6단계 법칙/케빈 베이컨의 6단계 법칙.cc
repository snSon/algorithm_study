#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> inputs(n + 1);
    for(int i = 0; i < m; i++){
        int s, e;
        std::cin >> s >> e;

        inputs[s].push_back(e);
        inputs[e].push_back(s);
    }

    int person_idx = 0, min_kebin = INT_MAX;

    for(int i = 1; i <= n; i++){
        std::vector<int> dist(n + 1, -1);
        std::queue<int> q;

        q.push(i);
        dist[i] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int next : inputs[curr]){
                if(dist[next] == -1){
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        int curr_kebin = 0;
        for(int d : dist){
            curr_kebin += d;
        }

        if(curr_kebin < min_kebin){
            min_kebin = curr_kebin;
            person_idx = i;
        }
    }

    std::cout << person_idx << std::endl;
}