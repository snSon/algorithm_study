#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<char> &alphabet, vector<string> &results, string cur){
    if(cur.size() > 5) return;
    if(!cur.empty()) results.push_back(cur);
    
    for(char c : alphabet) {
        dfs(alphabet, results, cur + c);
    }
}

int solution(string word) {
    vector<char> alphabet = {'A', 'E', 'I', 'O', 'U'};
    vector<string> results;
    
    dfs(alphabet, results, "");
    
    sort(results.begin(), results.end());
    
    auto it = find(results.begin(), results.end(), word);
    return distance(results.begin(), it) + 1;
    
}