// https://atcoder.jp/contests/abc279/submissions/65772568
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int ans = 0;
    for (char c : S) {
        if (c == 'w') ans += 2;
        else ans += 1;
    }
    cout << ans << "\n";
}