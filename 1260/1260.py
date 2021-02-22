from collections import deque

def wfs(route, start, option = 'bfs'):
    queue = deque([start])
    visited = []

    while queue:
        v = queue.popleft() if option == 'bfs' else queue.pop()

        if v not in visited:
            visited.append(v)
            unvisited = list(set(route[v]) - set(visited))
            unvisited.sort(reverse = False if option == 'bfs' else True)
            queue.extend(unvisited)

    return [str(x) for x in visited]

n, m, v = map(int, input().split())
route = [[] for _ in range(n + 1)]

for i in range(m):
    x, y = map(int, input().split())
    route[x].append(y)
    route[y].append(x)

print(' '.join(wfs(route, v, 'dfs')))
print(' '.join(wfs(route, v, 'bfs')))
