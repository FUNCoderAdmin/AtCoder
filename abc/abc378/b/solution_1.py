N = int(input())
garbage = [list(map(int, input().split())) for _ in range(N)]
Q = int(input())
for _ in range(Q):
    t, d = map(int, input().split())
    q, r = garbage[t - 1]
    rem = d % q
    if r >= rem:
        print(d + r - rem)
    else:
        print(d + r - rem + q)