#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> s_numbers;
    for(auto &n : numbers){
        s_numbers.push_back(to_string(n));
    }
    
    sort(s_numbers.begin(), s_numbers.end(), compare);
    
    string answer;
    for(auto &s : s_numbers){
        answer += s;
    }
    
    if (answer[0] == '0') answer = "0";
    
    return answer;
}