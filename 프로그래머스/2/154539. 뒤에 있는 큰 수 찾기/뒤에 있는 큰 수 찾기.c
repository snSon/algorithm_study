#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int numbers[], size_t numbers_len) {
    int* stack = (int*)malloc(sizeof(int) * numbers_len);
    int* answer = (int*)malloc(sizeof(int) * numbers_len);
    
    int top = -1;
    for(int i = numbers_len - 1; i >= 0; i--){
        if(top == -1){
            answer[i] = -1;
            stack[++top] = numbers[i];
            continue;
        }
        while(stack[top] <= numbers[i] && top >= 0)
            top--;
        
        if(top == -1){
            answer[i] = -1;
            stack[++top] = numbers[i];
            continue;
        }
        answer[i] = stack[top];
        stack[++top] = numbers[i];
    }
    
    return answer;
}