#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int rows = arr1.size();
    int cols = arr1[0].size();
    
    for(int i = 0; i < rows; i++){
        vector<int> row;
        for(int j = 0; j < cols; j++){
            row.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(row);
    }
    return answer;
}