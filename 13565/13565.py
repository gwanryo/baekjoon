from collections import deque
import sys
input = lambda: sys.stdin.readline().rstrip()
q = deque()

def main():
    h, w = map(int, input().split())
    grid = [list(input()) for _ in range(h)]

    for j in range(w):
        if grid[0][j] == '0':
            q.append((0, j))
            grid[0][j] = '2'

    while q:
        x, y = q.popleft()
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < h and 0 <= ny < w and grid[nx][ny] == '0':
                if nx == h - 1:
                    print('YES')
                    return
                q.append((nx, ny))
                grid[nx][ny] = '2'

    print('NO')

if __name__ == "__main__":
    main()