# https://atcoder.jp/contests/abc288/submissions/65805963
N, M = map(int, input().split())
from atcoder.dsu import DSU

uf = DSU(N)
ans = 0
for _ in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    if uf.same(a, b):
        ans += 1
    else:
        uf.merge(a, b)
print(ans)
