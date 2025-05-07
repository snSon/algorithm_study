#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int sort_by_idx = -1;

bool cmp(vector<int> &v1, vector<int> &v2){
    return v1[sort_by_idx] < v2[sort_by_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int ext_idx = -1;
    if(ext == "code")
        ext_idx = 0;
    else if(ext == "date")
        ext_idx = 1;
    else if(ext == "maximum")
        ext_idx = 2;
    else
        ext_idx = 3;
    
    
    for(auto a : data){
        if(a[ext_idx] < val_ext){
            answer.push_back(a);
        }
        
    }
    
    if(sort_by == "code")
        sort_by_idx = 0;
    else if(sort_by == "date")
        sort_by_idx = 1;
    else if(sort_by == "maximum")
        sort_by_idx = 2;
    else
        sort_by_idx = 3;
    
    sort(answer.begin(), answer.end(), cmp);
        
    
    return answer;
}