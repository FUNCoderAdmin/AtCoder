# https://atcoder.jp/contests/abc035/submissions/65805573
W, H = map(int, input().split())

if W * 3 == H * 4:
    print("4:3")
else:
    print("16:9")