#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* code) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int answer_len = 0;
    char* answer = (char*)malloc(answer_len + 1);
    
    int code_len = strlen(code);
    int mode = 0;
    
    for(int idx = 0; idx < code_len; idx++){
        if(code[idx] == '1'){
            mode = !mode;
        }
        else if(!mode ^ (idx & 1)){
            answer_len++;
            answer = (char*)realloc(answer, sizeof(char) * (answer_len + 1));
            answer[answer_len - 1] = code[idx];
        }
    }
    
    if(answer_len == 0){
        return "EMPTY";
    }
    answer[answer_len] = '\0';
    
    
    return answer;
}