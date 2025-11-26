#include <iostream>

int main(){
    int n;
    std::cin >> n;

    bool is_generated = false;
    for(int i = 1; i < n; i++){
        int sum = i;
        int temp = i;
        while(temp != 0){
            sum += temp%10;
            temp /= 10;
        }

        if(sum == n){
            std::cout << i << '\n';
            is_generated = true;
            break;
        }
    }

    if(!is_generated){
        std::cout << "0\n";
    }

    return 0;
}