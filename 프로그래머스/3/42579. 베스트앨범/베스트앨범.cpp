#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> total;
    map<string, vector<pair<int, int>>> songs;
    
    for(int i = 0; i < genres.size(); ++i){
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sorted(total.begin(), total.end());
    sort(sorted.begin(), sorted.end(), [](auto &a, auto &b){return a.second > b.second;});
    
    vector<int> answer;
    
    for(auto &g : sorted){
        auto &song = songs[g.first];
        sort(song.begin(), song.end(), [](auto &a, auto &b){
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        
        for(int i = 0; i < song.size() && i < 2; i++){
            answer.push_back(song[i].first);
        }
    }
    
    return answer;
}