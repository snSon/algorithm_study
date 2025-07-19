#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int k;
    cin >> k;

    int num;
    for(int i = 0; i < k; i++){
        cin >> num;
        num ? v.push_back(num) : v.pop_back();
    }

    int sum = 0;
    for(auto a = v.begin(); a != v.end(); a++){
        sum += *a;
    }

    cout << sum << endl;

    return 0;
}