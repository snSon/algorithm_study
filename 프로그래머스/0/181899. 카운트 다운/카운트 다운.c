#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int start_num, int end_num) {
    int answer_len = start_num - end_num + 1;
    int* answer = (int*)malloc(sizeof(int) * answer_len);
    
    for(int i = 0; i < answer_len; i++)
        answer[i] = start_num--;
    
    return answer;
}