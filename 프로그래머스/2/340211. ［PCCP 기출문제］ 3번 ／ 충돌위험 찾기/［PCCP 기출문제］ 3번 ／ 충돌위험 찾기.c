#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int location[101][101] = {0,};

int solution(int** points, size_t points_rows, size_t points_cols, int** routes, size_t routes_rows, size_t routes_cols) {
    int answer = 0;
    
    // 로봇의 위치 변수 정의 및 초기화
    int** robots_points = (int**)malloc(sizeof(int*) * routes_rows);
    for(int i = 0; i < routes_rows; i++){
        robots_points[i] = (int*)malloc(sizeof(int) * 2);
        int start_point = routes[i][0];
        robots_points[i][0] = points[start_point - 1][0];
        robots_points[i][1] = points[start_point - 1][1];
        
        location[robots_points[i][0]][robots_points[i][1]]++;
    }
    
    // 로봇별 경로
    int* robots_idx = (int*)malloc(sizeof(int) * routes_rows);
    for(int i = 0; i < routes_rows; i++){
        robots_idx[i] = 1;
    }
    
    
    // 초기 중첩 위치 확인
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(location[i][j] > 1){
                answer++;
            }
            location[i][j] = 0;
        }
    }
    
    int end = 0;
    int time = 0;
    // 모든 점이 경로를 완수할 때까지
    while(end != routes_rows){
        // 로봇마다 1칸 이동
        time++;
        for(int i = 0; i < routes_rows; i++){
            if(robots_idx[i] > routes_cols)
                continue;
                
            if(robots_idx[i] == routes_cols){
                robots_idx[i]++;
                end++;
                continue;
            }
            
            int next_point = routes[i][robots_idx[i]] - 1;
            
            // row 이동
            if(robots_points[i][0] > points[next_point][0])
                robots_points[i][0]--;
            else if(robots_points[i][0] < points[next_point][0])
                robots_points[i][0]++;
            // col 이동
            else{
                if(robots_points[i][1] > points[next_point][1])
                    robots_points[i][1]--;
                else if(robots_points[i][1] < points[next_point][1])
                    robots_points[i][1]++;
            }
            
            if(robots_points[i][0] == points[next_point][0] && robots_points[i][1] == points[next_point][1])
                robots_idx[i]++;
            
            location[robots_points[i][0]][robots_points[i][1]]++;
        }
        
        for(int i = 1; i <= 100; i++){
            for(int j = 1; j <= 100; j++){
                if(location[i][j] > 1){
                    answer++;
                }
                location[i][j] = 0;
            }
        }
    }
    
    return answer;
}