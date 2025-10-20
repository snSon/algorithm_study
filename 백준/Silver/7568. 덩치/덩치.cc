#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //inputs
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> inputs(n);

    int weight, height;
    for(int i = 0; i < n; i++){
        std::cin >> weight >> height;
        inputs[i] = {weight, height};
    }

    for(int i = 0; i < n; i++){
        int grade = 1;
        for(int j = 0; j < n; j++){
            if(i == j)
                continue;
            if(inputs[i].first < inputs[j].first
               && inputs[i].second < inputs[j].second){
                    grade++;
               }
        }
        std::cout << grade << " ";
    }

    std::cout << "\n";
    
    return 0;
}