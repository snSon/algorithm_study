#include <string>
#include <vector>

using namespace std;

void hanoi(int start, int mid, int end, int n, vector<vector<int>>& answer){
    if(n <= 1){
        vector<int> v;
        v.push_back(start);
        v.push_back(end);
        answer.push_back(v);
        
        return;
    }
    
    hanoi(start, end, mid, n-1, answer);
    
    vector<int> v;
    v.push_back(start);
    v.push_back(end);
    answer.push_back(v);
    
    hanoi(mid, start, end, n-1, answer);
    
    return;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(1, 2, 3, n, answer);
    
    return answer;
}