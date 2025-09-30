#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> &numbers, int target, int result, int idx){
    if(idx == numbers.size()){
        return result == target ? 1 : 0;
    }
    
    return dfs(numbers, target, result + numbers[idx], idx + 1)
        + dfs(numbers, target, result - numbers[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}