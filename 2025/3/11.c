#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    
    return GCD(b, a % b);
}

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = 1;
    
    qsort(arr, arr_len, sizeof(int), compare);
    
    for(int i = 0; i < arr_len; i++){
        answer *= arr[i] / GCD(answer, arr[i]);
    }
    
    return answer;
}
