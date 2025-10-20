#include <iostream>
#include <string>
#include <cmath>

int main(){
    int r= 31, M = 1234567891;
    int L;
    std::string s;

    std::cin >> L >> s;

    // process
    int hash_num = 0;
    for(int i = 0; i < L; i++){
        hash_num += (int)pow(r, i) * (s[i] - 'a' + 1) % M;
    }

    std::cout << hash_num << "\n";
    
    return 0;
}