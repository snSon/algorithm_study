#include <iostream>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int m;
    std::cin >> m;

    int bit = 0;
    
    for(int i = 0; i < m; i++){
        std::string command;
        int num;
        std::cin >> command;

        if(command == "all"){
            bit = (1 << 21) - 1;
        }
        else if(command == "empty"){
            bit = 0;
        }
        else{
            std::cin >> num;
        }

        if(command == "add"){
            bit |= (1 << num);
        }
        else if(command == "remove"){
            bit &= ~(1 << num);
        }
        else if(command == "check"){
            std::cout << (bit & (1 << num) ? 1 : 0) << "\n";
        }
        else if(command == "toggle"){
            bit ^= (1 << num);
        }
        else{
            continue;
        }
    }

    return 0;
}