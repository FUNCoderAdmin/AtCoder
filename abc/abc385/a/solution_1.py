A, B, C = map(int, input().split())
A, B, C = sorted([A, B, C])
print("Yes" if A == C or A + B == C else "No")