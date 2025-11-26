#include <iostream>
#include <stack>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;

    std::stack<int> st;
    for(int i = 0; i < n; i++){
        std::string command;
        std::cin >> command;

        if(command == "push"){
            int num;
            std::cin>> num;
            st.push(num);
        }
        else if(command == "pop"){
            if(st.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << st.top() <<'\n';
            st.pop();
        }
        else if(command == "size"){
            std::cout << st.size() << '\n';
        }
        else if(command == "empty"){
            std::cout << st.empty() << '\n';
        }
        else{
            if(st.empty()){
                std::cout << "-1\n";
                continue;
            }
            std::cout << st.top() << '\n';
        }
    }

    return 0;
}