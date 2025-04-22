#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* strArr[], size_t strArr_len) {
    char** answer = (char**)malloc(sizeof(char*) * strArr_len);
    
    int cnt = 0;
    for(int i = 0; i < strArr_len; i++){
        if(strstr(strArr[i], "ad") != NULL)
            continue;
        
        answer[cnt] = (char*)malloc(sizeof(char) * (strlen(strArr[i]) + 1));
        strcpy(answer[cnt], strArr[i]);
        cnt++;
    }
    
    answer = (char*)realloc(answer, sizeof(char*) * cnt);
    return answer;
}