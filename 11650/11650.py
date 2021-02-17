import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
p = []
for _ in range(n):
    x, y = map(int, input().split())
    p.append((x, y))

p.sort()
for x, y in p:
    print(x, y)
