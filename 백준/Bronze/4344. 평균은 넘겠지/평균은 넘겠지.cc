#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(){
    int C;
    std::cin >> C;

    std::vector<int> v;
    int N, number;
    for(int i = 0; i < C; i++){
        float sum = 0.0;
        std::cin >> N;

        for(int j = 0; j < N; j++){
            std::cin >> number;
            sum += (float)number;
            v.push_back(number);
        }

        sum /= N;

        int cnt = count_if(v.begin(), v.end(), [&](int x){
            return x > sum;
        });

        v.clear();

        std::cout << std::fixed << std::setprecision(3) << (float)cnt/N*100 << "%\n";
    }

    return 0;
}