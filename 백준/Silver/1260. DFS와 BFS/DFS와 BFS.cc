#include <iostream>
#include <vector>
#include <queue>

void dfs(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, int v, int n){
    std::cout << v << " ";
    visited[v] = true;

    for(int i = 1; i <= n; i++){
        if(graph[v][i] && !visited[i]){
            dfs(graph, visited, i, n);
        }
    }

    return;
}

int main(){
    int n, m, v;
    std::cin >> n >> m >> v;

    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++){
        int s, e;
        std::cin >> s >> e;

        graph[s][e] = 1;
        graph[e][s] = 1;
    }

    std::vector<bool> visited(n + 1, false);
    dfs(graph, visited, v, n);
    std::cout << std::endl;

    // dfs
    visited.clear();
    visited.assign(n + 1, false);
    std::queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        std::cout << curr << " ";

        for(int i = 1; i <= n; i++){
            if(graph[curr][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    std::cout << std::endl;

    return 0;
}