#include <bits/stdc++.h>
using namespace std;

using i64 = __int64_t;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    S += '0';

    int ans = N;
    for (int i = 0; i < N; i++) {
        int tmp = S[i] - S[i + 1];
        if (tmp < 0) tmp += 10;
        ans += tmp;
    }
    cout << ans << "\n";
}