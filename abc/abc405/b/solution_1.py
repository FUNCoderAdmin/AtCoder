N, M = map(int, input().split())
A = list(map(int, input().split()))

full_set = set(A)
if any(x not in full_set for x in range(1, M + 1)):
    print(0)
else:
    seen = [False] * (M + 1)
    cnt = 0
    R = N
    for i, a in enumerate(A, start=1):
        if 1 <= a <= M and not seen[a]:
            seen[a] = True
            cnt += 1
            if cnt == M:
                R = i
                break
    
    print(N - R + 1)