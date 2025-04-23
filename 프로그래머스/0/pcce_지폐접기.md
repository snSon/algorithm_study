# 문제
주어진 지갑의 크기에 주어진 지폐를 반씩 접어서 넣을 수 있도록 하는 문제

### 나의 풀이
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int wallet_width = wallet[0];
    int wallet_height = wallet[1];
    
    int bill_width = bill[0];
    int bill_height = bill[1];
    
    if(wallet_height > wallet_width){
        int temp = wallet_height;
        wallet_height = wallet_width;
        wallet_width = temp;
    }
    
    if(bill_height > bill_width){
        int temp = bill_height;
        bill_height = bill_width;
        bill_width = temp;
    }
    
    while(wallet_height < bill_height || wallet_width < bill_width){
        bill_width /= 2;
        if(bill_height > bill_width){
            int temp = bill_height;
            bill_height = bill_width;
            bill_width = temp;
        }
        
        answer++;
    }
    
    return answer;
}

### 피드백
변수를 새로 선언하지 않고 벡터를 정렬해서 계속 쓰는 것이 효율적일 것 같다.
