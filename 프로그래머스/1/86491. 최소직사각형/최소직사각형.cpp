#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int wallet[2] = {0, 0};
    int wallet_size = 0;
    for(auto &bcard : sizes){
        int resize, rotate_resize;
        if(bcard[0] > wallet[0] || bcard[1] > wallet[1]){
            resize = max(bcard[0], wallet[0]) * max(bcard[1], wallet[1]);
        }
        else{
            continue;
        }
        
        if(bcard[1] > wallet[0] || bcard[0] > wallet[1]){
            rotate_resize = max(bcard[1], wallet[0]) * max(bcard[0], wallet[1]);
        }
        else{
            continue;
        }
        
        if(resize < rotate_resize){
            wallet[0] = max(bcard[0], wallet[0]);
            wallet[1] = max(bcard[1], wallet[1]);
            //printf("resize : %d %d\n", wallet[0], wallet[1]);
        }
        else{
            wallet[1] = max(bcard[0], wallet[1]);
            wallet[0] = max(bcard[1], wallet[0]);
            //printf("rot_resize : %d %d\n", wallet[0], wallet[1]);
        }
    }
    
    return wallet[0] * wallet[1];
}