S = input()
T = input()
idx = 0
ans = []
for i in range(len(T)):
    if T[i] == S[idx]:
        idx += 1
        ans.append(i + 1)
print(*ans)