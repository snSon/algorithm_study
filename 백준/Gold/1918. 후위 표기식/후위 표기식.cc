#include <iostream>
#include <stack>
#include <vector>

int main(){
    std::string input;
    std::cin >> input;

    std::stack<char> alphabets;
    std::vector<std::stack<char>> ops(100);
    int par_count = 0;

    for(char c : input){
        if(c == '('){
            par_count++;
        }
        else if(c == ')'){
            while(!ops[par_count].empty()){
                std::cout << ops[par_count].top();
                ops[par_count].pop();
            }
            par_count--;
        }
        else if(c == '*' || c == '/'){
            if(ops[par_count].empty()){
                ops[par_count].push(c);
            }
            else{
                if(ops[par_count].top() == '+' || ops[par_count].top() == '-'){
                    ops[par_count].push(c);
                }
                else{
                    std::cout << ops[par_count].top();
                    ops[par_count].pop();
                    ops[par_count].push(c);
                }
            }
        }
        else if(c == '+' || c == '-'){
            if(ops[par_count].empty()){
                ops[par_count].push(c);
            }
            else{
                if(ops[par_count].top() == '+' || ops[par_count].top() == '-'){
                    std::cout << ops[par_count].top();
                    ops[par_count].pop();
                    ops[par_count].push(c);
                }
                else{
                    std::cout << ops[par_count].top();
                    ops[par_count].pop();
                    if(!ops[par_count].empty()){
                        std::cout << ops[par_count].top();
                        ops[par_count].pop();
                    }
                    ops[par_count].push(c);
                }
            }
        }
        else{
            std::cout << c;
        }
    }

    while(!ops[0].empty()){
        std::cout << ops[0].top();
        ops[0].pop();
    }
    std::cout << std::endl;

    return 0;
}