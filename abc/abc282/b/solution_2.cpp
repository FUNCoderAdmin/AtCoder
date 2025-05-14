#include <bits/stdc++.h>
using namespace std;

// for (int i = 0; i < N; i++) を rep(i, N) で書けるようにする
#define rep(i, N) for (int i = 0; i < (N); i++)
// 64bit の long long を ll と書けるようにする
using ll = long long;
int main() {
    int N, M;
    cin >> N >> M;
    vector<unsigned int> S(N);
    rep(i, N) {
        rep(j, M) {
            char c;
            cin >> c;
            if (c == 'o') S[i] |= (1 << j);
        }
    }

    int ans = 0;
    rep(i, N) {
        rep(j, i) {
            if (popcount(S[i] | S[j]) == M)
                ans++;
        }
    }
    cout << ans << "\n";
}