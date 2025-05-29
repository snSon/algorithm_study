#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int cnt = 0;
    while(cnt < 500){
        if(num == 1)
            break;
        if(num % 2 == 1)
            num = 3 * num + 1;
        else
            num /= 2;
        cnt++;
    }
    
    if(cnt == 500 && num != 1)
        cnt = -1;
    
    return cnt;
}