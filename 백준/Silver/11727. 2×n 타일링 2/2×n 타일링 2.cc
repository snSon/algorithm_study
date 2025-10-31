#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    std::vector<int> dp_arr(n + 1);
    dp_arr[0] = 0;
    dp_arr[1] = 1;

    if(n >= 2){
        dp_arr[2] = 3;
        for(int i = 3; i <= n; i++){
            dp_arr[i] = (dp_arr[i - 2] * 2 + dp_arr[i - 1]) %10007 ;
        }
    }

    std::cout << dp_arr[n] << std::endl;

    return 0;
}