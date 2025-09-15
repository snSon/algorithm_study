#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> um;
    for(auto &c : clothes){
        um[c[1]]++;
    }
    int answer = 1;
    
    for(auto &c : um){
        answer *= (c.second + 1);
    }
    return answer - 1;
}