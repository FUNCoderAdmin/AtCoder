// https://atcoder.jp/contests/abc268/submissions/65772743
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 5;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    // https://cpprefjp.github.io/reference/algorithm/unique.html
    A.erase(unique(A.begin(), A.end()), A.end());
    cout << A.size() << "\n";
}