#include <iostream>
#include <vector>
#include <climits>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1, std::vector<int>(n + 1, INT_MAX));
    for(int i = 1; i <= n; i++){
        graph[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b, c;
        std::cin >> a >> b >> c;

        graph[a][b] = std::min(graph[a][b], c);
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         std::cout << graph[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    for(int k = 0; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j || i == k || k == j){
                    continue;
                }
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX){
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(graph[i][j] == INT_MAX){
                std::cout << "0 ";
            }
            else{
                std::cout << graph[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}