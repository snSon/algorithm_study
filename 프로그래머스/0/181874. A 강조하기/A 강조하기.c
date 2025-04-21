#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* myString) {
    int myString_len = strlen(myString);
    
    char* answer = (char*)malloc(sizeof(char) * (myString_len + 1));
    for(int i = 0; i < myString_len; i++){
        if(myString[i] == 97)
            answer[i] = myString[i] -32;
        else if(myString[i] == 65 || myString[i] == 32)
            answer[i] = myString[i];
        else{
            answer[i] = (myString[i] >= 65 && myString[i] <= 90) ? myString[i] + 32 : myString[i];
        }
    }
    
    answer[myString_len] = '\0';
    return answer;
}