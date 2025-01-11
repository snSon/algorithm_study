#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n = 0;
    scanf("%d", &n);

    char input[101];
    int group_count = 0;
    for(int i = 0; i < n; i++){
        scanf("%s", input);

        int is_group = 1;
        int str_len = strlen(input);
        char prev_word = input[0];
        char* words = (char*)malloc(sizeof(char) * str_len);
        words[0] = input[0];
        int words_idx = 1;

        for(int j = 1; j < str_len; j++){
            char curr_word = input[j];

            if(prev_word == curr_word){
                continue;
            }
            else{
                for(int k = 0; k < words_idx; k++){
                    if(words[k] == curr_word){
                        is_group = 0;
                        break;
                    }
                }

                if(is_group){
                    words_idx++;
                    words[words_idx] = curr_word;
                    prev_word = curr_word;
                }
                else{
                    break;
                }
            }
        }

        if(is_group){
            // printf("%s", input);
            group_count++;
        }
    }

    printf("%d\n", group_count);

    return 0;
}
