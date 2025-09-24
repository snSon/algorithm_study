#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    int p1_size = 5, p2_size = 8, p3_size = 10;
    vector<int> random_pick_1 = {1, 2, 3, 4, 5};
    vector<int> random_pick_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> random_pick_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i = 0; i < answers.size(); i++){
        if(random_pick_1[i % p1_size] == answers[i]) c1++;
        if(random_pick_2[i % p2_size] == answers[i]) c2++;
        if(random_pick_3[i % p3_size] == answers[i]) c3++;
    }
    
    vector<int> answer;
    
    if(c1 > c2){
        if(c1 > c3)
            answer.push_back(1);
        else if(c1 == c3){
            answer.push_back(1);
            answer.push_back(3);
        }
        else{
            answer.push_back(3);
        }
    }
    else if(c1 == c2){
        if(c1 > c3){
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(c1 == c3){
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else{
            answer.push_back(3);
        }
    }
    else{
        if(c2 > c3){
            answer.push_back(2);
        }
        else if(c2 == c3){
            answer.push_back(2);
            answer.push_back(3);
        }
        else{
            answer.push_back(3);
        }
    }
    
    return answer;
}