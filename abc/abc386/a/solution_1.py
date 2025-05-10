A, B, C, D = map(int, input().split())
A, B, C, D = sorted([A, B, C, D])
if (A == C and C != D) or (A != B and B == D) or (A == B and B != C and C == D):
    print("Yes")
else:
    print("No")