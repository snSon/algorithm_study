#include <iostream>

int main(){
    int num;
    std::cin >> num;

    int temp = -1;
    int cnt = 0;
    int left = num / 10;
    int right = num % 10;
    while(temp != num){
        int sum = left + right;
        temp = right * 10 + sum % 10;
        left = temp / 10;
        right = temp % 10;
        cnt++;
    }

    std::cout << cnt << '\n';

    return 0;
}