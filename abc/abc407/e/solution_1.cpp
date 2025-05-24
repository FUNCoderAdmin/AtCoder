#include <bits/stdc++.h>
using namespace std;

using i64 = __int64_t;
using pi64 = pair<i64, i64>;
constexpr i64 INFL = 1ll << 60;
void solve() {
    i64 N;
    cin >> N;
    vector<i64> A(2 * N);
    for (i64 i = 0; i < 2 * N; i++)
        cin >> A[i];

    i64 ans = A[0];
    priority_queue<i64> pq;
    for (i64 i = 1; i + 1 < 2 * N; i += 2) {
        pq.push(A[i]);
        pq.push(A[i + 1]);
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";
}
int main() {
    i64 T;
    cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}