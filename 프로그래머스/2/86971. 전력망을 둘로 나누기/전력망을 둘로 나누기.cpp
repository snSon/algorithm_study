#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>> &graph, vector<int> &visited, int num){
    visited[num] = 1;
    int cnt = 1;
    for(auto &next : graph[num]){
        if(!visited[next]){
            cnt += dfs(graph, visited, next);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    for(auto& w : wires){
        int a = w[0];
        int b = w[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int answer = n;
    for(auto& w : wires){
        int a = w[0], b = w[1];
        graph[a].erase(find(graph[a].begin(), graph[a].end(), b));
        graph[b].erase(find(graph[b].begin(), graph[b].end(), a));
        
        vector<int> visited(n + 1, 0);
        int left = dfs(graph, visited, a);
        int right = n - left;
        
        answer = min(answer, abs(right - left));
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    return answer;
}