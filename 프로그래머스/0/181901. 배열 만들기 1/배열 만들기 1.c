#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, int k) {
    int mult_count = n / k;
    int* answer = (int*)malloc(sizeof(int) * mult_count);
    
    for(int i = 0; i < mult_count; i++)
        answer[i] = (i + 1) * k;
    
    return answer;
}