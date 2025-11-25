#include <iostream>

int main(){
    int n;
    std::string s;
    std::cin >> n >> s;
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += s[i] - '0';
    }
    
    std::cout << sum << '\n';
    
    return 0;
}