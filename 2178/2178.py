from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip()

def bfs(route, start):
    n, m = len(route), len(route[0])
    queue = deque()
    queue.append(start)

    while queue:
        x, y = queue.popleft()

        if x == n - 1 and y == m - 1:
            print(route[x][y])
            break

        if x + 1 < n and route[x + 1][y] == -1:
            queue.append((x + 1, y))
            route[x + 1][y] = route[x][y] + 1

        if x - 1 >= 0 and route[x - 1][y] == -1:
            queue.append((x - 1, y))
            route[x - 1][y] = route[x][y] + 1

        if y + 1 < m and route[x][y + 1] == -1:
            queue.append((x, y + 1))
            route[x][y + 1] = route[x][y] + 1

        if y - 1 >= 0 and route[x][y - 1] == -1:
            queue.append((x, y - 1))
            route[x][y - 1] = route[x][y] + 1

n, m = map(int, input().split())
route = [[] for _ in range(n)]

for i in range(n):
    s = input()
    for c in s:
        route[i].append(-int(c))

route[0][0] = 1
bfs(route, (0, 0))