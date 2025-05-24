#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using i64 = __int64_t;
using pi64 = pair<i64, i64>;
constexpr i64 INFL = 1ll << 60;
pi64 op(pi64 a, pi64 b) {
    return max(a, b);
}
pi64 e() {
    return {-INFL, -1};
}
int main() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    vector<i64> ans(N + 1);
    segtree<pi64, op, e> seg(N);
    for (int i = 0; i < N; i++)
        seg.set(i, {A[i], i});

    auto dfs = [&](auto f, i64 l, i64 r) {
        if (r <= l) return;
        auto [mx, idx] = seg.prod(l, r);
        ans[r - l] += mx;
        ans[idx - l] -= mx;
        ans[r - idx - 1] -= mx;
        f(f, l, idx);
        f(f, idx + 1, r);
    };
    dfs(dfs, 0, N);
    for (int j = 0; j < 2; j++) {
        for (int i = N; i > 0; i--)
            ans[i - 1] += ans[i];
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}