#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* my_string, const char* alp) {
    int my_string_len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char) * (my_string_len + 1));
    
    for(int i = 0; i < my_string_len; i++)
        answer[i] = (my_string[i] == alp[0]) ? alp[0] - 32 : my_string[i];
    
    answer[my_string_len] = '\0';
    
    return answer;
}