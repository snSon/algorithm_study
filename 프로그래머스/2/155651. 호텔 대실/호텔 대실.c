#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int start;
    int end;
}RentTime;

// 문자열 시간을 정수형으로 변환
int time_to_num(const char* time){
    int num = 0;
    for(int i = 0; i < 5; i++){
        if(i == 2)
            continue;
        num = num*10 + (time[i] - '0');
    }
    
    return num;
}

int compare(const void *a, const void *b){
    RentTime *t1 = (RentTime*)a;
    RentTime *t2 = (RentTime*)b;
    
    return t1->start - t2->start;
}

int add_10_minute(int t){
    int h = t/100;
    int m = t%100 + 10;
    if(m >= 60){
        h++;
        m %= 60;
    }
    return h*100 + m;
}

int solution(const char*** book_time, size_t book_time_rows, size_t book_time_cols) {
    RentTime *times = (RentTime*)malloc(sizeof(RentTime) * book_time_rows);
    for(int i = 0; i < book_time_rows; i++){
        times[i].start = time_to_num(book_time[i][0]);
        times[i].end = time_to_num(book_time[i][1]);
    }
    // 대실 시작 시간을 기준으로 오름차순 정렬
    qsort(times, book_time_rows, sizeof(RentTime), compare);

    int* rooms = (int*)malloc(sizeof(int) * book_time_rows);
    int cnt = 0;
    
    // 예약 순회
    for(int i = 0; i < book_time_rows; i++){
        int enter_time = times[i].start;
        int leave_time = times[i].end;
        
        // 입장 가능 유무 탐색
        int j;
        for(j = 0; j < cnt; j++){
            if(enter_time >= add_10_minute(rooms[j])){
                rooms[j] = leave_time;
                break;
            }
        }
        
        if(j == cnt){
            // printf("not exist : %d\n", time_to_num(book_time[i][1]));
            rooms[cnt++] = leave_time;
        }
    }
    
    free(times);
    free(rooms);
    
    return cnt;
}