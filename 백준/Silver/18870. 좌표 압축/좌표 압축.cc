#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());

    for(int x : v){
        std::cout << std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() << " ";
    }
    std::cout << std::endl;

    return 0;
}