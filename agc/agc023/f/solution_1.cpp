#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using i32 = int;
using i64 = long long;
using pi64 = pair<i64, i64>;
#define rep(i, N) for (i64 i = 0; i < (N); i++)

struct S {
    i64 num_0, num_1;
    i32 idx;
    S() : num_0(0), num_1(0), idx(-1) {}
    S(i32 num_0, i32 num_1, i32 idx) : num_0(num_0), num_1(num_1), idx(idx) {}
    strong_ordering operator<=>(const S& other) const {
        i64 a = num_1 * other.num_0;
        i64 b = other.num_1 * num_0;
        if (a != b) return a <=> b;
        return idx <=> other.idx;
    }
    S& operator+=(const S& other) {
        num_0 += other.num_0;
        num_1 += other.num_1;
        return *this;
    }
    friend ostream& operator<<(ostream& os, const S& s) {
        return os << s.num_0 << " " << s.num_1 << " " << s.idx;
    }
};

int main() {
    i32 N;
    cin >> N;
    vector<i32> P(N, -1), V(N);
    for (i32 i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    rep(i, N) cin >> V[i];

    multiset<S> st;
    vector<S> dp(N);
    rep(i, N) {
        dp[i] = S(V[i] == 0, V[i] == 1, i);
        st.insert(dp[i]);
    }

    i64 ans = 0;
    dsu uf(N);
    vector<i32> root(N);
    rep(i, N) root[i] = i;

    while (st.size() > 1) {
        auto now = *st.begin();
        if (now.idx == 0) now = *next(st.begin());
        st.erase(st.find(now));

        i32 par = root[uf.leader(P[now.idx])];
        st.erase(st.find(dp[par]));;
        
        ans += dp[par].num_1 * now.num_0;
        dp[par] += now;
        root[uf.merge(par, now.idx)] = par;
        st.insert(dp[par]);
    }
    cout << ans << "\n";
}