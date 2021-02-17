from collections import deque

n, k = map(int, input().split())
queue = deque()
queue.append((n, 0))
visited = {}
minTime, minCount = 100000, 0

while queue:
    node, time = queue.popleft()

    if node == k:
        if minTime > time:
            minTime = time
            minCount = 1
        elif minTime == time:
            minCount += 1

    if minTime <= time:
        continue

    if node < 0 or node > 100000 + 1:
        continue

    if visited.get(node) and time > visited[node]:
        continue

    visited[node] = time

    queue.append((node * 2, time + 1))
    queue.append((node - 1, time + 1))
    queue.append((node + 1, time + 1))

print(minTime)
print(minCount)