#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string a, b;
    std::cin >> a >> b;

    int a_len = a.length(), b_len = b.length();

    std::vector<std::vector<int>> dp_arr(a_len + 1, std::vector<int>(b_len + 1, 0));

    int max = -1;
    for(int i = 1; i <= a_len; i++){
        for(int j = 1; j <= b_len; j++){
            dp_arr[i][j] = (a[i - 1] == b[j - 1]) ? dp_arr[i - 1][j - 1] + 1 
                : std::max(dp_arr[i - 1][j], dp_arr[i][j - 1]);
        }
    }

    // for(int i = 0; i <= a_len; i++){
    //     for(int j = 0; j <= b_len; j++){
    //         std::cout << dp_arr[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << dp_arr[a_len][b_len] << std::endl;

    return 0;
}