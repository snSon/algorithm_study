#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1, 0);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
    }

    std::vector<int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + v[i];
    }
   
    for(int i = 0; i < m; i++){
        int s, e;
        std::cin >> s >> e;

        std::cout << prefix[e] - prefix[s - 1] << "\n";
    }

    return 0;
}