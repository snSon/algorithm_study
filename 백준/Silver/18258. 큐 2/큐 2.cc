#include <iostream>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;

    std::queue<int> q;
    for(int i = 0; i < n; i++){
        std::string command;
        std::cin >> command;

        if(command == "push"){
            int num;
            std::cin >> num;

            q.push(num);
        }
        else if(command == "pop"){
            if(q.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << q.front() << '\n';
            q.pop();
        }
        else if(command == "size"){
            std::cout << q.size() << '\n';
        }
        else if(command == "empty"){
            std::cout << q.empty() << '\n';
        }
        else if(command == "front"){
            if(q.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << q.front() << '\n';
        }
        else{
            if(q.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << q.back() << '\n';
        }
    }

    return 0;
}