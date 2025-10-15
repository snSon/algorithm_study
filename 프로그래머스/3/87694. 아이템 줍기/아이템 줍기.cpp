#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

struct Node{
    int x, y, dist;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> graph(102, vector<int>(102, 0));
    
    for(auto &r : rectangle){
        for(int i = r[0]*2; i <= r[2]*2; i++){
            for(int j = r[1]*2; j <= r[3]*2; j++){
                graph[i][j] = 1;
            }
        }
    }
    
    for(auto &r : rectangle){
        for(int i = r[0]*2 + 1; i < r[2]*2; i++){
            for(int j = r[1]*2 + 1; j < r[3]*2; j++){
                graph[i][j] = 0;
            }
        }
    }
    
    int mx[4] = {1, -1, 0, 0};
    int my[4] = {0, 0, 1, -1};
    
    queue<Node> q;
    vector<vector<int>> visited(102, vector<int>(102, 0));
    q.push({characterX*2, characterY*2, 0});
    visited[characterX*2][characterY*2] = 1;
    
    
    while(!q.empty()){
        Node curr = q.front();
        q.pop();
        
        if(curr.x == itemX*2 && curr.y == itemY*2){
            return curr.dist/2;
        }
        
        for(int i = 0; i < 4; i++){
            int next_x = curr.x + mx[i];
            int next_y = curr.y + my[i];
            
            if(next_x < 1 || next_x > 101 || next_y < 1 || next_y > 101)
                continue;
            
            if(!visited[next_x][next_y] && graph[next_x][next_y]){
                visited[next_x][next_y] = 1;
                q.push({next_x, next_y, curr.dist + 1});
            }
        }
    }
    
    
    return -1;
}