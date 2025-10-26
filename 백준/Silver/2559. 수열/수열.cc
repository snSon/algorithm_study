#include <iostream>
#include <vector>
#include <climits>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> temps(n);
    for(int i = 0; i < n; i++){
        std::cin >> temps[i];
    }

    std::vector<int> acc_sum(n);
    acc_sum[0] = temps[0];
    for(int i = 1; i < n; i++){
        acc_sum[i] = acc_sum[i - 1] + temps[i];
    }

    int k_temp_sum = acc_sum[k - 1];
    for(int i = k; i < n; i++){
        if(acc_sum[i] - acc_sum[i - k] > k_temp_sum){
            k_temp_sum = acc_sum[i] - acc_sum[i - k];
        }
    }

    std::cout << k_temp_sum << std::endl;

    return 0;
}