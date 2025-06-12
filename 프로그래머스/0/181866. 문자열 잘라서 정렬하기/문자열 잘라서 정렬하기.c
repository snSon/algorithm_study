#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    const char *p1 = *(const char**)a;
    const char *p2 = *(const char**)b;
    return strcmp(p1, p2);
}

char** solution(const char* myString) {
    int len = strlen(myString);
    char** temp = (char**)malloc(sizeof(char*) * len);
    int count = 0;

    const char* start = myString;
    const char* ptr = myString;

    while (*ptr) {
        if (*ptr == 'x') {
            if (start != ptr) {
                int wordLen = ptr - start;
                char* word = (char*)malloc(wordLen + 1);
                strncpy(word, start, wordLen);
                word[wordLen] = '\0';
                temp[count++] = word;
            }
            start = ptr + 1;
        }
        ptr++;
    }

    // 마지막 문자열 처리
    if (start != ptr) {
        int wordLen = ptr - start;
        char* word = (char*)malloc(wordLen + 1);
        strncpy(word, start, wordLen);
        word[wordLen] = '\0';
        temp[count++] = word;
    }

    qsort(temp, count, sizeof(char*), compare);
    return temp;
}
