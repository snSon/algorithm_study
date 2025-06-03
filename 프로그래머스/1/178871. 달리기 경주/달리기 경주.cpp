#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> idxMap;

    // 이름 → 인덱스 매핑
    for (int i = 0; i < players.size(); ++i) {
        idxMap[players[i]] = i;
    }

    for (string& name : callings) {
        int i = idxMap[name];
        if (i == 0) continue;

        // swap players
        swap(players[i], players[i - 1]);

        // 인덱스 업데이트
        idxMap[players[i]] = i;
        idxMap[players[i - 1]] = i - 1;
    }

    return players;
}
