#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;

    std::vector<std::string> inputs(n);

    for(int i = 0; i < n; i++){
        std::cin >> inputs[i];
    }

    sort(inputs.begin(), inputs.end(), 
        [] (const std::string &a, const std::string &b){
            if(a.length() < b.length()){
                return true;
            }
            else if(a.length() == b.length()){
                return a < b;
            }
            else{
                return false;
            }
        });
    inputs.erase(unique(inputs.begin(), inputs.end()), inputs.end());
    
    for(std::string &s : inputs){
        std::cout << s << '\n';
    }

    return 0;
}