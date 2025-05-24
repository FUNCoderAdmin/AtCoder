#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = 0, diff = A;
    for (int i = 0; i <= A; i++) {
        int tmp = abs(A - i * B);
        if (tmp < diff) {
            ans = i;
            diff = tmp;
        }
    }
    cout << ans << "\n";
}