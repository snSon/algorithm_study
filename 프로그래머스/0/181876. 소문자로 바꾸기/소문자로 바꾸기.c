#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* myString) {
    int myString_len = strlen(myString);
    char* answer = (char*)malloc(sizeof(char) * (myString_len + 1));
    
    for(int i = 0; i < myString_len; i++){
        if(myString[i] <= 'Z')
            answer[i] = myString[i] + 32;
        else
            answer[i] = myString[i];
    }
    
    answer[myString_len] = '\0';
    
    return answer;
}