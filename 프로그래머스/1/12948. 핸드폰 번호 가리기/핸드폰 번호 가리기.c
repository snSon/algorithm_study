#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* phone_number) {
    int answer_len = strlen(phone_number);
    char* answer = (char*)malloc(sizeof(char) * (answer_len + 1));
    
    for(int i = answer_len - 1; i >= 0; i--){
        answer[i] = (i > answer_len - 5) ? phone_number[i] : '*';
    }
    answer[answer_len] = '\0';
    
    return answer;
}