# https://atcoder.jp/contests/abc021/submissions/65805774
N = int(input())
a, b = map(int, input().split())
K = int(input())
P = list(map(int, input().split()))
P_set = {a, b} | set(P)
print("YES" if len(P_set) == (K + 2) else "NO")