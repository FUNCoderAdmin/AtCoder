# https://atcoder.jp/contests/abc223/submissions/65805880
N = int(input())
AB = [list(map(int, input().split())) for _ in range(N)]

x = 0
for a, b in AB:
    x += a / b
x /= 2

cur = 0
for a, b in AB:
    if x <= a / b:
        print(cur + x * b)
        break
    cur += a
    x -= a / b
