from collections import deque

n, k = map(int, input().split())
queue = deque()
queue.append((n, 0))
visited = {}
visited[n] = n

while queue:
    node, time = queue.popleft()

    if node == k:
        print(time)
        break

    if node * 2 <= 100000 and visited.get(node * 2) == None:
        visited.setdefault(node * 2, node)
        queue.append((node * 2, time + 1))

    if node - 1 >= 0 and visited.get(node - 1) == None:
        visited.setdefault(node - 1, node)
        queue.append((node - 1, time + 1))

    if node + 1 <= 100000 and visited.get(node + 1) == None:
        visited.setdefault(node + 1, node)
        queue.append((node + 1, time + 1))

result = f"{k}"
prev = visited[k]
while prev != visited[prev]:
    result = f"{prev} " + result
    prev = visited[prev]

print(f"{n} {result if n != k else ''}")