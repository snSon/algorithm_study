#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;
    
    int cnt = 0;

    for(int i = 0; i < input.size(); i++) {
        if(input[i] == 'c') {
            if(input[i + 1] == '=' || input[i + 1] == '-') 
                i++;
        }
        else if(input[i] == 'd') {
            if(input[i + 1] == 'z' && input[i + 2] == '=')
                i += 2;
            else if(input[i + 1] == '-')
                i++;
        }
        else if(input[i] == 'l' && input[i + 1] == 'j')
            i++;
        else if(input[i] == 'n' && input[i + 1] == 'j')
            i++;
        else if(input[i] == 's' && input[i + 1] == '=')
            i++;
        else if(input[i] == 'z' && input[i + 1] == '=')
            i++;
        
        cnt++;
    }

    std::cout << cnt << "\n";

    return 0;
}