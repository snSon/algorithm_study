#include <string>
#include <vector>
#include <iostream>

using namespace std;

// string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
//     int idx_1 = 0, idx_2 = 0;
//     for(int i = 0; i < goal.size(); i++){
//         while(1){
//             if(idx_1 >= cards1.size() && idx_2 >= cards2.size()){
//                 return "No";
//             }
//             if(cards1[idx_1] == goal[i]){
//                 idx_1++;
//                 break;
//             }
//             else if(cards2[idx_2] == goal[i]){
//                 idx_2++;
//                 break;
//             }
//             else{
//                 idx_1++;
//                 idx_2++;
//             }
//         }
//     }
    
//     return "Yes";
// }

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx_1 = 0, idx_2 = 0;
    for(int i = 0; i < goal.size(); i++){
        if(idx_1 < cards1.size() && cards1[idx_1] == goal[i]){
            idx_1++;
        }
        else if(idx_2 < cards2.size() && cards2[idx_2] == goal[i]){
            idx_2++;
        }
        else{
            return "No";
        }
    }
    return "Yes";
}
