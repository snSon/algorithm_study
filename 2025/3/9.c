// for(int = 0; i < strlen(s); i++) 금지!! 조건 검사마다 strlen()을 계산하므로 n^2의 시간복잡도를 가지게 됨.



#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// char stack[100001];

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    bool answer = true;
    
    int i = 0;
    int top = -1;
    while(s[i] != '\0'){
        if(s[i] == '('){
            top++;
        }
        else{
            if(top == -1){
                answer = false;
                break;
            }
            else{
               top--;
            }
        }
        i++;
    }
    
    if(top != -1){
        answer = false;
    }
    
    return answer;
}
