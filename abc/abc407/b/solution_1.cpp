#include <bits/stdc++.h>
using namespace std;

using i64 = __int64_t;

int main() {
    int X, Y;
    cin >> X >> Y;
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j >= X || abs(i - j) >= Y) {
                ans++;
            }
        }
    }
    cout << fixed << setprecision(20);
    cout << double(ans) / 36 << "\n";
}