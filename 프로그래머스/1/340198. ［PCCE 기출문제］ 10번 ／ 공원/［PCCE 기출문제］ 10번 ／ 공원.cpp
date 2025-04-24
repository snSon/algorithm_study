#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    int mats_num = mats.size();
    int park_row = park.size();
    int park_col = park[0].size();
    
    printf("row : %d    col : %d\n", park_row, park_col);
    for(int i = 0; i < park_row; i++){
        for(int j = 0; j < park_col; j++){
            if(park[i][j] != "-1"){
                continue;
            }
            
            for(int k = mats_num - 1; k >= 0; k--){
                int curr_mat_size = mats[k];
                
                int is_empty = 1;
                for(int r = 0; r < curr_mat_size; r++){
                    for(int q = 0; q < curr_mat_size; q++){
                        
                        if((i + r) >= park_row || (j + q) >= park_col){
                            is_empty = 0;
                            break;
                        }
                        
                        if(park[i + r][j + q] != "-1"){
                            is_empty = 0;
                            break;
                        }
                    }
                }
                
                if(is_empty && answer < curr_mat_size){
                    answer = curr_mat_size;
                }
            }
        }
    }
    
    return answer;
}