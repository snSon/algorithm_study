#include <iostream>
#include <vector>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    std::vector<int> v;

    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;

        if(x == 0){
            if(min_heap.empty()){
                v.push_back(0);
            }
            else{
                v.push_back(min_heap.top());
                min_heap.pop();
            }
        }
        else{
            min_heap.push(x);
        }
    }

    for(int num : v){
        std::cout << num << "\n";
    }

    return 0;
}