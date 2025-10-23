#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string input;
    std::cin >> input;

    int num = 0;
    std::vector<int> nums;
    std::vector<char> ops;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == '+' || input[i] == '-'){
            nums.push_back(num);
            ops.push_back(input[i]);
            num = 0;
        }
        else{
            num *= 10;
            num += input[i] - '0';
        }
    }
    nums.push_back(num);

    for(int i = (int)ops.size() - 1; i >= 0; i--){
        if(ops[i] == '+'){
            nums[i] += nums[i + 1];
            ops.erase(ops.begin() + i);
            nums.erase(nums.begin() + i + 1);
        }
    }

    int result = nums[0];
    for(int i = 1; i < nums.size(); i++){
        result -= nums[i];
    }

    std::cout << result << std::endl;

    return 0;
}