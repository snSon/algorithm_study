#include <iostream>
#include <cmath>

int binary_divide(int n, int r, int c){
    if(n < 0){
        return 0;
    }
    // std::cout << n << " " << r << " " << c << std::endl;

    int half = pow(2, n - 1);

    if(r >= half){
        if(c >= half){
            // std::cout << "4사분면" << std::endl;
            return half * half * 3 + binary_divide(n - 1, r - half, c - half);
        }
        else{
            // std::cout << "3사분면" << std::endl;
            return half * half * 2 + binary_divide(n - 1, r - half, c);
        }
    }
    else{
        if(c >= half){
            // std::cout << "2사분면" << std::endl;
            return half * half + binary_divide(n - 1, r, c - half);
        }
        else{
            // std::cout << "1사분면" << std::endl;
            return binary_divide(n - 1, r, c);
        }
    }
}

int main(){
    int n;
    std::cin >> n;

    int r, c;
    std::cin >> r >> c;

    std::cout << binary_divide(n, r, c) << std::endl;

    return 0;
}