#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int nm = n*m;
    
    if(n < m){
        int temp = n;
        n = m;
        m = temp;
    }
    
    while(m != 0){
        int mod = n % m;
        n = m;
        m = mod;
    }
    
    answer.push_back(n);
    int lcd = nm/n;
    answer.push_back(lcd);
    
    return answer;
}