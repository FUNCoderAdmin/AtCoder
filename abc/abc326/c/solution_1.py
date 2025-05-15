# https://atcoder.jp/contests/abc326/submissions/65805674
N, M = map(int,input().split())
A = list(map(int, input().split()))

from bisect import bisect_left

A.sort()
ans = 0
for i in range(N):
    r = A[i] + M
    tmp = bisect_left(A, r) - i
    ans = max(ans, tmp)
print(ans)
