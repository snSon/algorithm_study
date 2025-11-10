#include <iostream>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> items(n);
    for(int i = 0; i < n; i++){
        int w, v;
        std::cin >> w >> v;
        items[i] = {w, v};
    }

    std::vector<std::vector<int>> dp_arr(n + 1, std::vector<int>(k + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            auto [curr_w, curr_v] = items[i - 1];
            if(curr_w > j){
                dp_arr[i][j] = dp_arr[i - 1][j];
            }
            else{
                dp_arr[i][j] = std::max(dp_arr[i - 1][j], dp_arr[i - 1][j - curr_w] + curr_v);
            }
        }
    }


    std::cout << dp_arr[n][k] << "\n";

    return 0;
}