#include <bits/stdc++.h>
using namespace std;

using i64 = __int64_t;
#define rep(i, N) for (i64 i = 0; i < (N); i++)~

i64 N, D1, D2;
using pi64 = pair<i64, i64>;
i64 id(i64 x, i64 y) {
    return x * 2 * N + y;
}

int main() {
    cin >> N >> D1 >> D2;
    if (D1 > D2) 
        swap(D1, D2);
    
    vector<pi64> edges;
    for (i64 x = 0; x * x <= D2; x++) {
        for (i64 y = 0; x * x + y * y <= D2; y++) {
            i64 d = x * x + y * y;
            if (d == D1) {
                edges.emplace_back(x, y);
            } 
            if (d == D2) {
                edges.emplace_back(x, y);
            }
        }
    }

}