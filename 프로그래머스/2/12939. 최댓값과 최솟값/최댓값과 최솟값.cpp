#include <string>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    string s_num;
    
    int min = INT_MAX;
    int max = INT_MAX;
    max++;
    
    while(ss >> s_num){
        int num = stoi(s_num);
        if(min > num)
            min = num;
        if(max < num)
            max = num;
    }
    
    answer = to_string(min) + " " + to_string(max);
    
    return answer;
}