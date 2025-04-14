#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len, int idx) {
    int answer = 0;
    
    int arr_idx = idx;
    while(arr_idx != arr_len){
        if(arr[arr_idx])
            break;
        arr_idx++;
    }
    
    if(arr_idx == arr_len)
        arr_idx = -1;
    
    answer = arr_idx;
        
    return answer;
}