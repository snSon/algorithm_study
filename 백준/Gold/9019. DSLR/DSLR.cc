#include <iostream>
#include <queue>

int main(){
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++){
        int a, b;
        std::cin >> a >> b;

        std::queue<std::pair<std::string, int>> q;
        std::vector<bool> visited(10001, false);

        q.push({"", a});
        visited[a] = true;

        while(!q.empty()){
            auto [command, num] = q.front();
            q.pop();

            if(num == b){
                std::cout << command << "\n";
                break;
            }

            int d_num = (num * 2) % 10000;
            int s_num = (num == 0) ? 9999 : num - 1;
            int l_num = (num * 10) % 10000 + (num * 10) / 10000;
            int r_num = (num % 10) * 1000 + (num / 10);
        
            if(!visited[d_num]){
                visited[d_num] = true;
                q.push({command + "D", d_num});
            }
            if(!visited[s_num]){
                visited[s_num] = true;
                q.push({command + "S", s_num});
            }
            if(!visited[l_num]){
                visited[l_num] = true;
                q.push({command + "L", l_num});
            }
            if(!visited[r_num]){
                visited[r_num] = true;
                q.push({command + "R", r_num});
            }
        }
    }

    return 0;
}
