#include <iostream>
#include <string>

int main(){
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;

    int idx = 0, cnt = 0;
    while(true){
        idx = s.find("IOI", idx);
        if(idx == -1)
            break;
        
        int curr_cnt = 0;
        while(s[idx + 1] == 'O' && s[idx + 2] == 'I'){
            curr_cnt++;
            idx += 2;
        }
        if(curr_cnt >= n){
            cnt += (curr_cnt + 1 - n);
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}