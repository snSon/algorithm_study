#include <iostream>
#include <vector>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


    int n;
    std::cin >> n;

    std::vector<std::vector<int>> tree(n + 1);

    for(int i = 0; i < n - 1; i++){
        int p, c;
        std::cin >> p >> c;
        tree[p].push_back(c);
        tree[c].push_back(p);
    }

    std::vector<int> parent(n + 1);
    std::queue<int> q;
    q.push(1);
    std::vector<bool> visited(n + 1, false);
    visited[1] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int next : tree[curr]){
            if(!visited[next]){
                parent[next] = curr;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    for(int i = 2; i <= n; i++){
        std::cout << parent[i] << "\n";
    }

    return 0;
}