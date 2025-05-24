#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

using i64 = __int64_t;
using pi64 = pair<i64, i64>;
using i128 = __int128_t;
constexpr i64 INFL = 1ll << 60;
constexpr array<pi64, 4> D = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
constexpr i64 TEN(i64 x) { return x == 0 ? 1 : 10 * TEN(x - 1); }
int main() {
    i64 H, W;
    cin >> H >> W;
    const i64 cost_add = TEN(12);
    vector<vector<i64>> A(H, vector<i64>(W));
    i128 sum = 0;
    for (i64 i = 0; i < H; i++) {
        for (i64 j = 0; j < W; j++) {
            cin >> A[i][j];
            sum += A[i][j];
        }
    }

    mcf_graph<i128, i128> g(H * W + 2);
    for (i64 x = 0; x < H; x++) {
        for (i64 y = 0; y < W; y++) {
            if ((x ^ y) & 1) {
                g.add_edge(x * W + y, H * W + 1, 1, cost_add + A[x][y]);
                continue;
            }
            g.add_edge(H * W, x * W + y, 1, cost_add + A[x][y]);
            for (auto [dx, dy] : D) {
                i64 nx = x + dx;
                i64 ny = y + dy;
                if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    g.add_edge(x * W + y, nx * W + ny, 1, 0);
                }
            }
        }
    }
    // g.flow(H * W, H * W + 1);
    auto slope = g.slope(H * W, H * W + 1);

    // cout << sum << "\n";
    i128 ans = sum;
    i128 cur_flow = 0, cur_cost = 0;
    for (auto [flow, cost] : slope) {
        if (flow != cur_flow){
            i128 d_cost = (cost - cur_cost) / (flow - cur_flow);
            for (; cur_flow < flow; cur_flow++, cur_cost += d_cost) {
                i128 tmp = cur_cost - 2 * cost_add * cur_flow;
                ans = max(ans, sum - tmp);
            }
        }
        cur_cost = cost;
        i128 tmp = cur_cost - 2 * cost_add * cur_flow;
        ans = max(ans, sum - tmp);
    }
    cout << (i64)ans << "\n";
}