#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    sort(v.begin(), v.end());

    int time = 0;
    int wait_time = 0;
    for(int t : v){
        time += wait_time + t;
        wait_time += t;
    }

    std::cout << time << '\n';

    return 0;
}