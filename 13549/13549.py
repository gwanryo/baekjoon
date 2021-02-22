from collections import deque

n, k = map(int, input().split())
queue = deque()
queue.append((n, 0))
visited = {}

while queue:
    node, time = queue.popleft()

    if node == k:
        print(time)
        break

    if node < 0 or node > 100000 + 1:
        continue

    if visited.get(node):
        continue

    visited[node] = time

    queue.append((node * 2, time))
    queue.append((node - 1, time + 1))
    queue.append((node + 1, time + 1))