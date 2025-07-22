#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void comb(vector<int> &inputs, vector<int> &choose, int start, int r){
    if(r == 0){
        for(auto a : choose){
            cout << a << " ";
        }
        cout << "\n";
        
        return;
    }

    for(int i = start; i < inputs.size(); i++){
        choose.push_back(inputs[i]);
        comb(inputs, choose, i + 1, r - 1);
        choose.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 자료 정의
    vector<int> v;
    int N, M;
    
    // 입력
    cin >> N >> M;
    int num;
    for(int i = 0; i < N; ++i){
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    vector<int> choose;
    comb(v, choose, 0, M);

    return 0;
}