#include <iostream>
#include <set>

int main(){
    int T;
    std::cin >> T;

    for(int i = 0; i < T; i++){
        int k;
        std::cin >> k;

        std::multiset<int> ms;
        for(int j = 0; j < k; j++){
            std::string command;
            int num;

            std::cin >> command >> num;

            if(command == "I"){
                ms.insert(num);
            }
            else{
                if(ms.empty()){
                    continue;
                }

                if(num == 1){
                    auto pos = std::prev(ms.end());
                    ms.erase(pos);
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()){
            std::cout << "EMPTY" << std::endl;
        }
        else{
            std::cout << *std::prev(ms.end()) << " " << *ms.begin() << std::endl;
        }
    }

    return 0;
}