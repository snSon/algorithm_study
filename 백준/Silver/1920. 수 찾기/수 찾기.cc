#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int m;
    cin >> m;

    int *exists = new int[m];
    int search_num;
    for(int i = 0; i < m; i++){
        cin >> search_num;
        exists[i] = binary_search(arr, arr + n, search_num);
    }

    for(int i = 0; i < m; i++){
        cout << exists[i] << "\n"; 
    }    

    delete[] arr;
    delete[] exists;

    return 0;
}