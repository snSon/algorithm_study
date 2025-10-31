#include <iostream>
#include <vector>
#include <queue>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::priority_queue<int> pq_minus;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq_plus;
    for(int i = 0; i < n; i++){
        int num;
        std::cin >> num;

        if(num == 0){
            if(pq_minus.empty() && pq_plus.empty()){
                std::cout << "0\n";
            }
            else{
                if(pq_minus.empty()){
                    std::cout << pq_plus.top() << "\n";
                    pq_plus.pop();
                }
                else if(pq_plus.empty()){
                    std::cout << pq_minus.top() << "\n";
                    pq_minus.pop();
                }
                else if(pq_minus.top() * -1 <= pq_plus.top()){
                    std::cout << pq_minus.top() << "\n";
                    pq_minus.pop();
                }
                else{
                    std::cout << pq_plus.top() << "\n";
                    pq_plus.pop();
                }
            }
        }
        else if(num < 0){
            pq_minus.push(num);
        }
        else{
            pq_plus.push(num);
        }
    }

    return 0;
}