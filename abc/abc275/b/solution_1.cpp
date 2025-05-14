// https://atcoder.jp/contests/abc275/submissions/65773434
#include <bits/stdc++.h>
using namespace std;

/*/
    int型は 32bit で 2 * 10^9 程度までしか扱えない
    そのため、64bit の long long型を使用する
    しかし、long long型の最大値も 9 * 10^18 程度なので、工夫する必要がある

    実は、(A + B) % MOD = ((A % MOD) + (B % MOD)) % MOD も同じ値になる
    引き算・掛け算(・特殊な方法の割り算)についても同様のことが言える
//*/
using ll = long long;
int main() {
    ll MOD = 998244353;
    vector<ll> A(6);
    for (int i = 0; i < 6; i++) {
        cin >> A[i];
        A[i] %= MOD;
    }
    ll add = 1, sub = 1;
    for (int i = 0; i < 3; i++) {
        add *= A[i];
        add %= MOD;
        sub *= A[3 + i];
        sub %= MOD;
    }
    ll ans = add - sub;
    ans %= MOD;
    // C++ の a % MOD は a が 0 未満のときに 0 未満となる
    if (ans < 0) ans += MOD; 
    cout << ans << "\n";
}