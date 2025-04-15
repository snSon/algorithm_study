#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// slicer_len은 배열 slicer의 길이입니다.
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int n, int slicer[], size_t slicer_len, int num_list[], size_t num_list_len) {
    int *answer = malloc(sizeof(int) * 26);
    
    int start = slicer[0];
    int end = slicer[1];
    int gap = 1;
    switch(n){
        case 1:
            start = 0;
            break;
        case 2:
            end = num_list_len - 1;
            break;
        case 4:
            gap = slicer[2];
            break;
    }
    
    int answer_idx = 0;
    for(int i = start; i <= end; i += gap)
        answer[answer_idx++] = num_list[i];
    
    answer = realloc(answer, sizeof(int) * answer_idx);
    
    return answer;
}