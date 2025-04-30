#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 현재 숙련도로 제한 시간 내에 퍼즐을 모두 해결할 수 있는지 검사하는 함수
bool canSolveAll(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit, int level) {
    long long totalTime = 0;
    int prevTime = times[0];

    for (size_t i = 0; i < diffs_len; i++) {
        if (diffs[i] <= level) {
            totalTime += times[i];
        } else {
            int mistakes = diffs[i] - level;
            totalTime += mistakes * (prevTime + times[i]) + times[i];
        }
        prevTime = times[i];

        if (totalTime > limit) {
            return false;
        }
    }
    return true;
}

int solution(int diffs[], size_t diffs_len, int times[], size_t times_len, long long limit) {
    // 이진 탐색을 위한 초기값 설정
    int low = 1;
    int high = 100000;
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSolveAll(diffs, diffs_len, times, times_len, limit, mid)) {
            answer = mid;
            high = mid - 1; // 더 작은 숙련도를 찾기 위해 상한을 낮춥니다.
        } else {
            low = mid + 1; // 더 높은 숙련도가 필요하므로 하한을 올립니다.
        }
    }

    return answer;
}
