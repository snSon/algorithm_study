#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int cal_weights(std::vector<std::vector<int>> &weights, std::vector<bool> &visited, int n){
    int start = 0, link = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(visited[i] && visited[j]){
                start += (weights[i][j] + weights[j][i]);
            }
            else if(!visited[i] && !visited[j]){
                link += (weights[i][j] + weights[j][i]);
            }
        }
    }

    return abs(start - link);
}

int dfs(std::vector<std::vector<int>> &weights, std::vector<bool> &visited, int start, int cnt, int n){
    if(cnt == n/2){
        return cal_weights(weights, visited, n);
    }

    int min_result = INT_MAX;
    for(int i = start; i < n; i++){
        visited[i] = true;
        int curr_result = dfs(weights, visited, i + 1, cnt + 1, n);
        visited[i] = false;

        if(curr_result < min_result){
            min_result = curr_result;
        }
    }

    return min_result;
}

int main(){
    // input
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int>> weights(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> weights[i][j];
        }
    }

    // processing
    std::vector<bool> visited(n, false);
    int result = dfs(weights, visited, 0, 0, n);

    std::cout << result << '\n';
    
    return 0;
}