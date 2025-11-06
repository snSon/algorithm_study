#include <iostream>
#include <vector>

void print_recursion(std::vector<std::vector<char>> &triangle, int x, int y, int size){
    if(size == 3){
        triangle[y][x] = '*';
        triangle[y + 1][x - 1] = '*';
        triangle[y + 1][x + 1] = '*';
        for(int i = -2; i <= 2; i++){
            triangle[y + 2][x + i] = '*';
        }

        return;
    }

    print_recursion(triangle, x, y, size/2);
    print_recursion(triangle, x - size/2, y + size/2, size/2);
    print_recursion(triangle, x + size/2, y + size/2, size/2);

    return;
}

int main(){
    int n;
    std::cin >> n;

    std::vector<std::vector<char>> triangle(n, std::vector<char>(2 * n - 1, ' '));
    print_recursion(triangle, n - 1, 0, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n - 1; j++){
            std::cout << triangle[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}