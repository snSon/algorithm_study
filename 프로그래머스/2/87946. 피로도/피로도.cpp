#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int permutation(vector<vector<int>> &dungeons, int k){
    if(k < 0)
        return 0;
    
    int max_results = 0;
    for(int i = 0; i < dungeons.size(); i++){
        auto stress = dungeons[i];
        dungeons.erase(dungeons.begin() + i);
        
        if(k >= stress[0]){
            int result = permutation(dungeons, k - stress[1]);
            max_results = max(max_results, result + 1);
        }
        dungeons.insert(dungeons.begin() + i, stress);
        
    }
    
    return max_results;
}
int solution(int k, vector<vector<int>> dungeons) {
    return permutation(dungeons, k);
}