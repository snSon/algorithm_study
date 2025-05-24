#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    int digit_sum = 0;
    int temp = x;
    while(temp != 0){
        digit_sum += (temp % 10);
        temp /= 10;
    }
    
    return (x % digit_sum) == 0;
}