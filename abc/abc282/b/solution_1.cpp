// https://atcoder.jp/contests/abc282/submissions/65773195
#include <bits/stdc++.h>
using namespace std;

// for (int i = 0; i < N; i++) を rep(i, N) で書けるようにする
#define rep(i, N) for (int i = 0; i < (N); i++)
// 64bit の long long を ll と書けるようにする
using ll = long long;
int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    rep(i, N) {
        cin >> S[i];
    }
    
    ll ans = 0;
    rep(i, N) {
        rep(j, i) {
            ll cnt = 0;
            rep(k, M) {
                if (S[i][k] == 'o' || S[j][k] == 'o')
                    cnt++;
            }
            if (cnt == M) ans++;
        }
    }
    cout << ans << "\n";
}