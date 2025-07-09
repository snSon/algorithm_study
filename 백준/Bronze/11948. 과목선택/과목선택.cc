#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[4];
    int b[2];

    for(int i = 0; i < 4; i++){
        cin >> a[i];
    }

    for(int i = 0; i < 2; i++){
        cin >> b[i];
    }

    sort(a, a + 4, greater<int>());
    sort(b, b + 2, greater<int>());

    int sum = 0;

    for(int i = 0; i < 3; i++){
        sum += a[i];
    }

    sum += b[0];

    cout << sum << endl;

    return 0;
}