#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    unordered_map<string, int> idxMap;
    vector<int> answer;
    
    // 이름 → 인덱스 매핑
    for (int i = 0; i < name.size(); ++i) {
        idxMap[name[i]] = yearning[i];
    }
    
    for(auto one_photo : photo){
        int yearning_score = 0;
        for(string &person : one_photo){
            yearning_score += idxMap[person];
        }
        answer.push_back(yearning_score);
    }
    
    return answer;
}