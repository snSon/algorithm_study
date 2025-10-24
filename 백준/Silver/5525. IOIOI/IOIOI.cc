#include <iostream>
#include <string>

int main(){
    int n, m;
    std::string s;

    std::cin >> n >> m >> s;

    std::string target = "I";
    for(int i = 0; i < n; i++){
        target += "OI";
    }

    int idx = 0, cnt = 0;
    while(true){
        idx = s.find(target, idx);
        if(idx == -1){
            break;
        }
        idx++;
        cnt++;
    }

    std::cout << cnt << std::endl;

    return 0;
}