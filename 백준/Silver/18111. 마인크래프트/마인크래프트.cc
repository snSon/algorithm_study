#include <iostream>
#include <vector>
#include <climits>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, b;
    std::cin >> n >> m >> b;

    std::vector<std::vector<int>> blocks(n, std::vector<int>(m));
    unsigned int min_h = 256;
    int max_h = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> blocks[i][j];

            if(min_h > blocks[i][j]){
                min_h = blocks[i][j];
            }
            if(max_h < blocks[i][j]){
                max_h = blocks[i][j];
            }
        }
    }


    int min_time = INT_MAX;
    int hightest_h = min_h;
    for(int i = min_h; i <= max_h; i++){
        int save_blocks = 0, drop_blocks = 0;

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(blocks[j][k] == i){
                    continue;
                }
                else if(blocks[j][k] < i){
                    drop_blocks += (i - blocks[j][k]);
                }
                else if(blocks[j][k] > i){
                    save_blocks += (blocks[j][k] - i);
                }
            }
        }

        if(save_blocks + b < drop_blocks){
            continue;
        }

        if(save_blocks * 2 + drop_blocks <= min_time){
            min_time = save_blocks * 2 + drop_blocks;
            hightest_h = i;
        }
    }

    std::cout << min_time << " " << hightest_h << std::endl;

    return 0;
}