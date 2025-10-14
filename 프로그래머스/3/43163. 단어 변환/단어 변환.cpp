#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int can_convert(string &a, string &b){
    int diff = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) diff++;
        if(diff > 1) return 0;
    }
    return diff;
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);
    q.push({begin, 0});
    
    while(!q.empty()){
        string current = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if(current == target)
            return step;
        
        for(int i = 0; i < words.size(); i++){
            if(!visited[i] && can_convert(current, words[i])){
                visited[i] = true;
                q.push({words[i], step + 1});
            }
        }
    }
    
    return 0;
}