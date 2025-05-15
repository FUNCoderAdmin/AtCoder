# https://atcoder.jp/contests/abc326/submissions/65807493
N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

ans = 0
r = 0
# A[l] に左端を投げると [l, r) 番目のプレゼントを捕まえられる
for l in range(N):
    while r < N and A[r] < A[l] + M:
        r += 1
    ans = max(ans, r - l)

print(ans)
