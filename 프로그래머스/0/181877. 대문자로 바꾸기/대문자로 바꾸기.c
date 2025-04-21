#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* myString) {
    int myString_len = strlen(myString);
    char* answer = (char*)malloc(sizeof(char) * (myString_len + 1));
    
    for(int i = 0; i < myString_len; i++){
        if(myString[i] >= 'a')
            answer[i] = myString[i] - 32;
        else
            answer[i] = myString[i];
    }
    
    answer[myString_len] = '\0';
    
    return answer;
}