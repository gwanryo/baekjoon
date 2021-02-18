import sys
input = lambda: sys.stdin.readline().rstrip()
def dfs(field, n, m, queue):
    while len(queue):
        x, y, c = queue.pop()

        if field[x][y] == -1:
            field[x][y] = c
        else:
            continue

        if x - 1 >= 0:
            if field[x - 1][y] == -1:
                queue.append((x - 1, y, c))

        if x + 1 < n:
            if field[x + 1][y] == -1:
                queue.append((x + 1, y, c))

        if y - 1 >= 0:
            if field[x][y - 1] == -1:
                queue.append((x, y - 1, c))

        if y + 1 < m:
            if field[x][y + 1] == -1:
                queue.append((x, y + 1, c))

t = int(input())
for _ in range(t):
    m, n, k = map(int, input().split())
    field = [[0] * m for _ in range(n)]
    point = []
    for _ in range(k):
        y, x = map(int, input().split())
        point.append((x, y))
        field[x][y] = -1
    
    count = 0
    for i, p in enumerate(point):
        if field[p[0]][p[1]] != -1:
            continue
        count += 1
        queue = [(p[0], p[1], count)]
        dfs(field, n, m, queue)

    print(count)
