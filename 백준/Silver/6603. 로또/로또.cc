#include <iostream>
#include <vector>

using namespace std;

void combination(vector<int> &seq, vector<int> &picks, int start, int remain){
    if(remain == 0){
        for(int num : picks){
            cout << num << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = start; i < seq.size(); i++){
        picks.push_back(seq[i]);
        combination(seq, picks, i + 1, remain - 1);
        picks.pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 자료 정의
    int N;
    cin >> N;

    while(N != 0){
        vector<int> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }

        vector<int> picks;
        combination(v, picks, 0, 6);

        cout << "\n";
        
        cin >> N;
    }

    return 0;
}