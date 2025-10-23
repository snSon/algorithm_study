#include <iostream>
#include <queue>
#include <vector>

int main(){
    int n, k;
    std::cin >> n >> k;

    std::queue<int> q;
    std::vector<int> position(100001, -1);
    q.push(n);
    position[n] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == k){
            break;
        }

        if(curr > 0 && (position[curr - 1] == -1 || position[curr - 1] > position[curr] + 1)){
            position[curr -1] = position[curr] + 1;
            q.push(curr - 1);
        }
        if(curr < 100000 && (position[curr + 1] == -1 || position[curr + 1] > position[curr] + 1)){
            position[curr + 1] = position[curr] + 1;
            q.push(curr + 1);
        }
        if(curr <= 50000 && (position[curr * 2] == -1 || position[curr * 2] > position[curr] + 1)){
            position[curr * 2] = position[curr] + 1;
            q.push(curr * 2);
        }
    }

    std::cout << position[k] << std::endl;

    return 0;
}