a, b, c = map(int, input().split())
a, b, c = sorted([a, b, c])
if a == b:
    print(c)
elif b == c:
    print(a)
else:
    print(0)