#include <iostream>
#include <vector>

int main(){
    std::string s;
    std::cin >> s;
    
    std::vector<int> cnt(26, 0);
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] <= 'Z'){
            cnt[s[i] - 'A']++;
        }
        else{
            cnt[s[i] - 'a']++;
        }
    }
    
    int max = -1;
    int max_idx = -1;
    bool is_same = false;
    
    for(int i = 0; i < 26; i++){
        if(cnt[i] > max){
            max = cnt[i];
            max_idx = i;
            is_same = false;
        }
        else if(cnt[i] == max){
            max = cnt[i];
            max_idx = i;
            is_same = true;
        }
    }
    
    if(is_same){
        std::cout << "?\n";
    }
    else{
        std::cout << (char)(max_idx + 'A') <<'\n';
    }
    
    return 0;
}