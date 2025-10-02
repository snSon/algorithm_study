#include<vector>
#include<queue>
using namespace std;


int solution(vector<vector<int>> maps)
{
    int n = maps.size(), m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    queue<pair<int, int>> q;
    
    int m_x[4] = {1, -1, 0, 0};
    int m_y[4] = {0, 0, 1, -1};
    
    q.push({0, 0});
    visited[0][0] = 1;
            
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        if(x == n - 1 && y == m - 1)
            return visited[x][y];
        
        for(int i = 0; i < 4; i++){
            int next_x = x + m_x[i];
            int next_y = y + m_y[i];
            
            if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m 
               && maps[next_x][next_y] && !visited[next_x][next_y]){
                visited[next_x][next_y] = visited[x][y] + 1;
                q.push({next_x, next_y});
            }
        }
    }
    
    
    return -1;
}