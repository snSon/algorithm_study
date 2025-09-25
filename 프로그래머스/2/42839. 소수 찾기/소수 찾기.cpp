#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

void permutation(vector<char> &v, int r, string &s, set<int> &results){
    if(r == 0){
        results.insert(stoi(s));
        return;
    }
    
    for(int i = 0; i < v.size(); i++){
        char c = v[i];
        s.push_back(c);
        v.erase(v.begin() + i);
        
        permutation(v, r - 1, s, results);
        
        v.insert(v.begin() + i, c);
        s.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;
    
    vector<char> v;
    for(int i = 0; i < numbers.length(); i++){
        v.push_back(numbers[i]);
    }
    
    set<int> results;
    string s;
    for(int i = 1; i <= numbers.length(); i++){
        permutation(v, i, s, results);
    }
    
    int max = *--results.end();
    
    vector<bool> isPrime(max + 1, true);
    isPrime[0] = false;
    if(max >= 1) isPrime[1] = false;
    
    for(int i = 2; i*i <= max; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= max; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    for(int num : results){
        if(isPrime[num]){
            answer++;
        }
    }
    
    return answer;
}