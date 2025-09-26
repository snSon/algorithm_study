#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h = 1, w = yellow;
    if(yellow <= 3){
        answer.push_back(w + 2);
        answer.push_back(h + 2);
    }
    for(int i = 2; i * i <= yellow; i++){
        if(yellow % i != 0)
            continue;
        
        h = i;
        w = yellow / i;
        // cout << "h : " << h << " w : " << w << "\n";
        
        if(brown == 2*(h + w + 2)){
            answer.push_back(w + 2);
            answer.push_back(h + 2);   
            break;
        }
    }
    return answer;
}