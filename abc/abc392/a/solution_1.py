A = list(map(int, input().split()))
B = sorted(A)
print("Yes" if B[0] * B[1] == B[2] else "No")