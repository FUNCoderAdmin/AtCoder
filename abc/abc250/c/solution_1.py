# https://atcoder.jp/contests/abc250/submissions/65806184
N, Q = map(int, input().split())
P = [i for i in range(N)]
P_inv = [i for i in range(N)]
# P[P_inv[i]] = i

for _ in range(Q):
    x = int(input()) - 1
    x_idx = P_inv[x]
    y = P[x_idx + 1] if x_idx + 1 != N else P[x_idx - 1]
    y_idx = P_inv[y]
    # print(f"{x = }, {x_idx = }, {y = }, {y_idx = }")
    P_inv[x], P_inv[y] = P_inv[y], P_inv[x]
    P[x_idx], P[y_idx] = P[y_idx], P[x_idx]
    # print(*P)
    # print(*P_inv)

for i in range(N):
    P[i] += 1
print(*P)