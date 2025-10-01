#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &computers, int num, int n){
    for(int i = 0; i < n; i++){
        if(computers[num][i]){
            computers[num][i] = 0;
            dfs(computers, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(computers[i][j]){
                answer++;
                computers[i][i] = 0;
                dfs(computers, i, n);
            }
        }
    }
    
    return answer;
}