#include <iostream>
#include <map>

int main(){
    int test_case;
    std::cin >> test_case;

    for(int i = 0; i < test_case; i++){
        int n;
        std::cin >> n;

        std::map<std::string, int> m;
        for(int j = 0; j < n; j++){
            std::string cloth, type;
            std::cin >> cloth >> type;
            m[type]++;
        }

        int result = 1;
        for(auto a : m){
            // std::cout << a.second << std::endl;
            result *= (a.second + 1);
        }

        std::cout << result - 1 << "\n";
    }

    return 0;
}