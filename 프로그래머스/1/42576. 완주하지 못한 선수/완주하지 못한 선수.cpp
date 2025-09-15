#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    m.reserve(participant.size() * 2);
    
    for(auto &p : participant) m[p]++;
    for(auto &c : completion) if(--m[c] == 0) m.erase(c);
    
    for(auto &kv : m) if (kv.second > 0) return kv.first;
    
    return {};
}