#include <iostream>

long long pow(int base, int exp, int c){
    if(exp == 0){
        return 1;
    }
    else if(exp == 1){
        return base % c;
    }

    long long divide = pow(base, exp/2, c);
    long long result = divide * divide % c;
    if(exp % 2){
        result = result * base % c;
    }
    return result ;
}

int main(){
    int a, b, c;
    
    std::cin >> a >> b >> c;

    std::cout << pow(a, b, c) << std::endl;

    return 0;
}