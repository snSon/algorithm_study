#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return strcmp(*(char**)a, *(char**)b);
}

char** solution(const char* my_string) {
    int ms_len = strlen(my_string);
    
    char** answer = (char**)malloc(sizeof(char*) * ms_len);
    for(int i = 0; i < ms_len; i++){
        answer[i] = & my_string[i];
    }
    
    qsort(answer, ms_len, sizeof(char*), compare);
    
    return answer;
}