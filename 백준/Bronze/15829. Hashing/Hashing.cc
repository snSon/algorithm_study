#include <iostream>
#include <string>
#include <cmath>

int main(){
    int r= 31, M = 1234567891;
    int L;
    std::string s;

    std::cin >> L >> s;

    // process
    long long hash_num = 0;
    long long pow_num = 1;
    for(int i = 0; i < L; i++){
        long long temp = (s[i] - 'a' + 1);
        hash_num = (hash_num + pow_num * temp) % M;
        pow_num = pow_num * r % M;
    }

    std::cout << hash_num << "\n";
    
    return 0;
}