#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    
    int n = s.length();
    int is_upper = 1;
    for(int i = 0; i < n; i++)
        if(s[i] == ' '){
            answer += s[i];
            is_upper = 1;
        }
        else if(is_upper){
            answer += (s[i] >= 'a' && s[i] <= 'z') ? s[i] - 32 : s[i];
            is_upper = 0;
        }
        else
            answer += (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
    
    return answer;
}