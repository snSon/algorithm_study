#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int> seq, vector<int> picks, int* visited, int remain){
    if(remain == 0){
        for(int num : picks){
            cout << num << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = 0; i < seq.size(); i++){
        if(visited[i]){
            continue;
        }

        picks.push_back(seq[i]);
        visited[i] = 1;
        permutation(seq, picks, visited, remain - 1);
        visited[i] = 0;
        picks.pop_back();
    }

    return;
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
    for(int i = 1; i <= N; i++){
        v.push_back(i);
    }

    int* visited = new int[N];
    for(int i = 0; i < N; i++){
        visited[i] = 0;
    }

    vector<int> picks;
    permutation(v, picks, visited, M);

    return 0;
}