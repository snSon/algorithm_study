#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    
    int odd_sum = 0, even_sum = 0;
    for(int i = 0; i < num_list_len; i++){
        if(i & 1)
            odd_sum += num_list[i];
        else
            even_sum += num_list[i];
    }
    
    answer = odd_sum > even_sum ? odd_sum : even_sum;
    
    return answer;
}