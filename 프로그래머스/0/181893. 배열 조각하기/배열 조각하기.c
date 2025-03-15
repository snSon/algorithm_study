#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// query_len은 배열 query의 길이입니다.
int* solution(int arr[], size_t arr_len, int query[], size_t query_len) {
    int answer_size = (query_len % 2 == 0) ? query[query_len - 2] + 1 : query[query_len - 1] + 1;
    int right = 0;
    for(int i = 1; i < query_len; i += 2)
        right += query[i];
    
    int* answer = (int*)malloc(sizeof(int) * (answer_size));
    for(int i = 0; i < answer_size; i++){
        answer[i] = arr[right + i];
    }
    
    return answer;
}