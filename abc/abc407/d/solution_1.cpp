#include <bits/stdc++.h>
using namespace std;

using i64 = __int64_t;
using pi64 = pair<i64, i64>;
constexpr i64 INFL = 1ll << 60;
constexpr array<pi64, 4> D = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
i64 check(i64 H, i64 W, const vector<vector<bool>>& S, const vector<vector<i64>>& A) {
    i64 ret = 0;
    vector used(H, vector<bool>(W, false));
    for (i64 i = 0; i < H; i++) {
        for (i64 j = 0; j < W; j++) {
            if (S[i][j]) {
                ret ^= A[i][j];
                continue;
            }
            if (used[i][j]) continue;

            i64 cnt = 0;
            queue<pi64> q({{i, j}});
            while(q.size() > 0) {
                auto [x, y] = q.front();
                q.pop();
                if (used[x][y]) continue;
                used[x][y] = true;
                if ((x + y) % 2 == 0) {
                    cnt++;
                } else {
                    cnt--;
                }

                for (auto [dx, dy] : D) {
                    i64 nx = x + dx;
                    i64 ny = y + dy;
                    if (0 <= nx && nx < H && 0 <= ny && ny < W
                        && !S[nx][ny] && !used[nx][ny]) {
                        q.push({nx, ny});
                    }
                }
            }
            if (cnt != 0) return -INFL;
        }
    }
    return ret;
}
int main() {
    i64 H, W;
    cin >> H >> W;

    vector A(H, vector<i64>(W));
    for (i64 i = 0; i < H; i++) {
        for (i64 j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    i64 ans = -INFL;
    i64 N = H * W;
    i64 M = 1ll << N;
    auto is1 = [&](i64 bit, i64 i, i64 j) {
        return (bit >> (i * W + j)) & 1;
    };
    vector S(H, vector<bool>(W, false));
    for (i64 bit = 0; bit < M; bit++) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                S[i][j] = is1(bit, i, j);
            }
        }
        ans = max(ans, check(H, W, S, A));
    }
    cout << ans << "\n";
}