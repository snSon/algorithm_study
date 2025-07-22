#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int left = 0, right = 0;
    vector<int> answer;
    int sum = sequence[0];
    int min_len = 1111111;
    
    while(left <= right && right < sequence.size()){
        if(sum == k){
            if(right - left + 1 < min_len){
                min_len = right - left + 1;
                answer = {left, right};
            }
            sum -= sequence[left++];
        }
        else if(sum > k){
            sum -= sequence[left++];
        }
        else{
            sum += sequence[++right];
        }
    }
    
    
    return answer;
}