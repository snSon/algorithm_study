#include <iostream>
#include <vector>
#include <queue>

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> graph(n, std::vector<bool>(n, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            bool num;
            std::cin >> num;
            if(num){
                graph[i][j] = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j]){
                std::queue<int> q;
                q.push(j);

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    graph[i][curr] = true;

                    for(int k = 0; k < n; k++){
                        if(graph[curr][k] && !graph[i][k]){
                            q.push(k);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}