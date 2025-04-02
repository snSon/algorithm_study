#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b) {
    int answer = 0;
    
    // a (+) b
    int b_digit = (int)log10(b) + 1;
    int ab = a * pow(10, b_digit) + b;

    // 2 * a * b
    int ab_2 = a * b * 2;
    
    answer = (ab >= ab_2) ? ab : ab_2;
    
    return answer;
}