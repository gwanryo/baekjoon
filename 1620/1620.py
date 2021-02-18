import sys
input = lambda: sys.stdin.readline().rstrip();d = {}
n, m = map(int, input().split())
for i in range(n):
    name = input()
    d[str(i + 1)] = name
    d[name] = i + 1
for i in range(m):
    print(d[input()])