#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    
    cin >> a >> b >> c;

    int abc = a*b*c;

    int result[10] = {0, };

    while(abc != 0){
        result[abc%10]++;
        abc /= 10;
    }

    for(int i = 0; i < 10; i++){
        cout << result[i] << endl;
    }

    return 0;
}