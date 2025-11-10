#include <iostream>

std::pair<long long, long long> fib(long long num){
    if(num == 0){
        return {0, 1};
    }

    auto divide_fib = fib(num/2);

    long long c = ((__int128)divide_fib.first * (2 * divide_fib.second - divide_fib.first + 1000000007) % 1000000007);
    long long d = ((__int128)divide_fib.first * divide_fib.first % 1000000007+ (__int128)divide_fib.second * divide_fib.second % 1000000007) % 1000000007;

    if(num % 2 == 0){
        return {c, d};
    }
    else{
        return {d, (c + d) % 1000000007};
    }
}

int main(){
    long long num;
    std::cin >> num;

    auto result = fib(num);

    std::cout << result.first << std::endl;

    return 0;
}