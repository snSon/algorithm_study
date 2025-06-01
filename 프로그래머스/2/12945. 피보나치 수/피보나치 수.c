#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    long long a = 0, b = 1;
    for(int i = 1; i < n; i++){
        long long temp = b;
        b = (b + a)%1234567; 
        a = temp;
    }
    
    answer = b % 1234567;
    
    return answer;
}