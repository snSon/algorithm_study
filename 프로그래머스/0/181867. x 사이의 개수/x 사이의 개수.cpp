#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int cnt = 0;
    for(int i = 0; i < myString.length(); i++){
        if(myString[i] == 'x'){
            answer.push_back(cnt);
            cnt = 0;
            continue;
        }
        cnt++;
    }
    answer.push_back(cnt);
    return answer;
}