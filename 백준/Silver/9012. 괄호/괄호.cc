#include <iostream>
#include <stack>

int main(){
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++){
        std::string s;
        std::cin >> s;

        std::stack<char> st;
        bool is_vps = true;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '('){
                st.push('(');
            }
            else{
                if(st.size() == 0){
                    is_vps = false;
                    break;
                }
                else{
                    st.pop();
                }
            }
        }

        if(is_vps == false || st.size() != 0){
            std::cout << "NO\n";
        }
        else{
            std::cout << "YES\n";
        }
    }

    return 0;
}