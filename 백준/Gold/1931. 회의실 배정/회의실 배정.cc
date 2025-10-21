#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct node{
    int count, idx, start, end;
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> inputs(n);
    for(int i = 0; i < n; i++){
        std::cin >> inputs[i].first >> inputs[i].second;
    }

    sort(inputs.begin(), inputs.end(),
         [](const std::pair<int, int> &a, const std::pair<int, int> &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
         });
    
    int meeting = 0;
    int end_time = 0;
    for(auto &m : inputs){
        if(m.first >= end_time){
            meeting++;
            end_time = m.second;
        }
    }

    std::cout << meeting << std::endl;

    return 0;
}