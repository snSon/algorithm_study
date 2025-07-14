#include <iostream>

using namespace std;

int main(){
    int inputs[5];

    for(int i = 0; i < 5; i++){
        cin >> inputs[i];
    }

    int cnt = 0;
    for(int i = 1; ; i++){
        cnt = 0;
        for(int j = 0; j < 5; j++){
            if(i % inputs[j] == 0)
                cnt++;
        }
        if(cnt >= 3){
            cout << i << endl;
            break;
        }
    }

    return 0;
}