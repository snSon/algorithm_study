#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    queue<int> q;
    vector<int> v;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        q.push(i + 1);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k - 1; j++){
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for(int i = 0; i < n - 1; i++){
        cout << v[i] << ", ";
    }
    cout << v[n-1] << ">" << "\n";

    return 0;
}