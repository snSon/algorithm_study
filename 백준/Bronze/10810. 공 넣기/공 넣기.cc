#include <iostream>

using namespace std;

int main(){
    int n, m;

    cin >> n >> m;

    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int start, end, num;
        cin >> start >> end >> num;

        for(int j = start - 1; j < end; j++){
            arr[j] = num;
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}