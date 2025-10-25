#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<int> basket(N);
    for (int i = 0; i < N; ++i) basket[i] = i + 1;

    for (int k = 0; k < M; ++k) {
        int i, j;
        cin >> i >> j;
        // 인덱스는 0-based로 변환
        reverse(basket.begin() + (i - 1), basket.begin() + j);
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << basket[i];
    }
    cout << '\n';
    return 0;
}
