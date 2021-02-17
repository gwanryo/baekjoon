from collections import deque

n, k = map(int, input().split())
queue = deque()
queue.append((n, 0))
visited = {}

while 1:
    node, time = queue.popleft()

    if node == k:
        print(time)
        break

    if visited.get(node):
        continue

    visited[node] = 1
    if node + 1 <= k + 1:
        queue.append((node + 1, time + 1))
    if node - 1 >= 0:
        queue.append((node - 1, time + 1))
    if node * 2 <= k + 1:
        queue.append((node * 2, time + 1))
