#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* strArr[], size_t strArr_len) {
    char** answer = (char**)malloc(sizeof(char*) * strArr_len);
    for(int i = 0; i < strArr_len; i++){
        int str_len = strlen(strArr[i]);
        answer[i] = (char*)malloc(sizeof(char*) * (str_len + 1));
        
        for(int j = 0; j < str_len; j++){
            if(i&1)
                answer[i][j] = (strArr[i][j] >= 97) ? strArr[i][j] - 32 : strArr[i][j];
            else
                answer[i][j] = (strArr[i][j] <= 90) ? strArr[i][j] + 32 : strArr[i][j];
        }
        
        answer[i][str_len] = '\0';
    }
    
    return answer;
}