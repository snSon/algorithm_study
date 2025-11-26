#include <iostream>
#include <deque>

int main(){
    int n;
    std::cin >> n;

    std::deque<int> dq;
    for(int i = 0; i < n; i++){
        std::string command;
        std::cin >> command;

        if(command == "push_front"){
            int num;
            std::cin >> num;
            dq.push_front(num);
        }
        else if(command == "push_back"){
            int num;
            std::cin >> num;
            dq.push_back(num);
        }
        else if(command == "pop_front"){
            if(dq.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << dq.front() << '\n';
            dq.pop_front();
        }
        else if(command == "pop_back"){
            if(dq.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << dq.back() << '\n';
            dq.pop_back();
        }
        else if(command == "size"){
            std::cout << dq.size() << '\n';
        }
        else if(command == "empty"){
            std::cout << dq.empty() << '\n';
        }
        else if(command == "front"){
            if(dq.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << dq.front() << '\n';
        }
        else{
            if(dq.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << dq.back() << '\n';
        }
    }

    return 0;
}