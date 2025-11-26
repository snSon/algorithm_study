#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> v;
    while(n != 0){
        v.push_back(n % 10);
        n /= 10;
    }

    sort(v.begin(), v.end(), std::greater<>());
    
    for(int n : v){
        std::cout << n;
    }
    std::cout << '\n';

    return 0;
}