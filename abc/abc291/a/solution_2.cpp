// https://atcoder.jp/contests/abc291/submissions/65772642
#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int N = S.size();

    for (int i = 0; i < N; i++) {
        if ('A' <= S[i] && S[i] <= 'Z') {
            cout << i + 1 << "\n";
        }
    }
}