#include <stdio.h>
#include <limits.h>
#include <string.h>

int compare_1(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int compare_2(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    
    qsort(A, A_len, sizeof(int), compare_1);
    qsort(B, B_len, sizeof(int), compare_2);
    
    for(int i = 0; i < A_len; i++){
       answer += A[i]*B[i];
    }
    
    return answer;
}