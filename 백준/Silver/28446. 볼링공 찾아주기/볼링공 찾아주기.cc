#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int> lockers;
    int M;
    cin >> M;
    
    int request, locker_num, ball_weights;
    for(int i = 0; i < M; i++){
        cin >> request;
        if(request == 1){
            cin >> locker_num >> ball_weights;
            lockers[ball_weights] = locker_num;
        }
        else if(request == 2){
            cin >> ball_weights;
            cout << lockers[ball_weights] << "\n";
        }
    }
    
    return 0;
}