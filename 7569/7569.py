from collections import deque

def is_fully_ripe(m):
    for a in m:
        for b in a:
            for c in b:
                if c == 0:
                    return False
    return True

m, n, h = map(int, input().split())
boxes = [[] for _ in [0] * h]
for i in range(h):
    for _ in [0] * n:
        boxes[i].append(list(map(int, input().split())))

if is_fully_ripe(boxes):
    print(0)
    exit()

current = 0
direction = [(1, 0, 0), (0, 1, 0), (0, 0, 1), (-1, 0, 0), (0, -1, 0), (0, 0, -1)]
q = deque()
for i, box in enumerate(boxes):
    for j, row in enumerate(box):
        for k, el in enumerate(row):
            if el == 1:
                q.append((i, j, k, 0))

while q:
    i, j, k, d = q.popleft()
    if d > current:
        current = d
    for vi, vj, vk in direction:
        if not (0 <= i + vi < h): continue
        if not (0 <= j + vj < n): continue
        if not (0 <= k + vk < m): continue

        if boxes[i + vi][j + vj][k + vk] == 0:
            boxes[i + vi][j + vj][k + vk] = 1
            q.append((i + vi, j + vj, k + vk, d + 1))

print(current if is_fully_ripe(boxes) else -1)