from collections import deque

H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
ds = ((-1, 0, "v"), (1, 0, "^"), (0, -1, ">"), (0, 1, "<"))
from_d = [[None] * W for _ in range(H)]
q = deque()

for i in range(H):
    for j in range(W):
        if S[i][j] == "E":
            q.append((i, j))
            from_d[i][j] = "E"

while q:
    now_i, now_j = q.popleft()
    for dy, dx, arrow in ds:
        next_i, next_j = now_i + dy, now_j + dx

        if not (0 <= next_i < H and 0 <= next_j < W):
            continue

        if not (S[next_i][next_j] == "." and from_d[next_i][next_j] is None):
            continue

        from_d[next_i][next_j] = arrow
        q.append((next_i, next_j))

ans = [[""] * W for _ in range(H)]

for i in range(H):
    for j in range(W):
        if S[i][j] == "#":
            ans[i][j] = "#"
        elif S[i][j] == "E":
            ans[i][j] = "E"
        else:
            ans[i][j] = from_d[i][j]

for row in ans:
    print("".join(row))
