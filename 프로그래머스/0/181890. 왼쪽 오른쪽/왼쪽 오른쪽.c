#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// str_list_len은 배열 str_list의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* str_list[], size_t str_list_len) {
    char** answer;
    
    int cnt = 0;
    int check_word = 0;
    for(int i = 0; i < str_list_len; i++){
        if(str_list[i][0] == 'l'){
            check_word = -1;
            break;
        }
        if(str_list[i][0] == 'r'){
            check_word = 1;
            break;
        }
        cnt++;
    }
    
    if(check_word == -1){
        answer = (char**)malloc(sizeof(char*) * cnt);
        for(int i = 0; i < cnt; i++){
            answer[i] = (char*)malloc(sizeof(char) * 2);
            answer[i][0] = str_list[i][0];
            answer[i][1] = '\0';
        }
    }
    else if(check_word == 1){
        answer = (char**)malloc(sizeof(char*) * (str_list_len - cnt - 1));
        for(int i = 0; i < str_list_len - cnt - 1; i++){
            answer[i] = (char*)malloc(sizeof(char) * 2);
            answer[i][0] = str_list[i + cnt + 1][0];
            answer[i][1] = '\0';
        }
    }
    return answer;
}