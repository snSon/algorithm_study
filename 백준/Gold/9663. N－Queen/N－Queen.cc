#include <iostream>
#include <vector>

int dfs(std::vector<bool> &visited_col, std::vector<bool> &diag1, std::vector<bool> &diag2, int row, int n){
    if(row == n){
        return 1;
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        int right_down = n - 1 + row - i;
        int left_down = i + row;
        if(!visited_col[i] && !diag1[right_down] && !diag2[left_down]){
            visited_col[i] = true;
            diag1[right_down] = true;
            diag2[left_down] = true;

            sum += dfs(visited_col, diag1, diag2, row + 1, n);

            visited_col[i] = false;
            diag1[right_down] = false;
            diag2[left_down] = false;
        }
    }

    return sum;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<bool> visited_col(n, false);
    std::vector<bool> diag1(2 * n - 1, false);
    std::vector<bool> diag2(2 * n - 1, false);


    std::cout << dfs(visited_col, diag1, diag2, 0, n) << std::endl;

    return 0;
}