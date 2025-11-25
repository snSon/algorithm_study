#include <iostream>
#include <vector>

int main(){
    int n;
    std::cin >> n;

    int result = 0;
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;

        std::vector<bool> checked(26, false);

        char prev = s[0];
        checked[s[0] - 'a'] = true;
        bool is_group = true;
        for(int j = 1; j < s.length(); j++){
            if(prev == s[j]){
                continue;
            }
            else{
                if(checked[s[j] - 'a']){
                    is_group = false;
                    break;
                }
                else{
                    prev= s[j];
                    checked[prev - 'a'] = true;
                }
            }
        }

        if(is_group){
            result++;
        }
    }

    std::cout << result << '\n';

    return 0;
}