from collections import deque

m, n = map(int, input().split())
a, q = [], deque()
for i in range(n):
    a.append([int(c) for c in input().split()])
    for j, b in enumerate(a[-1]):
        if b == 1:
            q.append((i, j))

direc = [(0, -1), (0, 1), (1, 0), (-1, 0)]
while q:
    x, y = q.popleft()
    for ax, ay in direc:
        cx, cy = x + ax, y + ay
        if 0 <= cx < n and 0 <= cy < m and a[cx][cy] == 0:
            a[cx][cy] = a[x][y] + 1
            q.append((cx, cy))

tmax, tflag = -1, False
for i in range(n):
    for j in range(m):
        if a[i][j] == 0:
            tflag = True
        elif a[i][j] > tmax:
            tmax = a[i][j]

print(-1 if tflag else tmax - 1)
