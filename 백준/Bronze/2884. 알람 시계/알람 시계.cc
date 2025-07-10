#include <iostream>

using namespace std;

int main(){
    int h, m;
    cin >> h >> m;

    if(m >= 45){
        m -= 45;
    }
    else{
        m = (m + 15) % 60;
        h--;
        if(h < 0){
            h = (h + 24) % 24;
        }
    }

    cout << h << " " << m << endl; 

    return 0;
}