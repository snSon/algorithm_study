#include <iostream>

int main(){
    int n;
    std::cin >> n;

    int draw[101][101] = {0,};

    int a, b;
    for(int i = 0; i < n; i++){
        std::cin >> a >> b;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                draw[a + j][b + k]++;
            }
        }
    }

    int result = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(draw[i][j] != 0){
                result++;
            }
        }
    }

    std::cout << result << '\n';

    return 0;
}