#include <iostream>

int main(){
    int x, n, a, b;
    std::cin >> x >> n;

    int result = 0;
    for(int i = 0; i < n; i++){
        std::cin >> a >> b;
        result += (a*b);
    }

    if(result == x){
        std::cout << "Yes\n";
    }
    else{
        std::cout << "No\n";
    }

    return 0;
}