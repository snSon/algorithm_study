#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int arr_1_rows = arr1.size();
    int arr_1_cols = arr1[0].size();
    int arr_2_cols = arr2[0].size();
    
    for(int i = 0; i < arr_1_rows; i++){
        vector<int> temp;
        for(int j = 0; j < arr_2_cols; j++){
            int sum = 0;
            for(int k = 0; k < arr_1_cols; k++){
                sum += arr1[i][k]*arr2[k][j];  
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }
    return answer;
}