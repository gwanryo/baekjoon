import sys
input = lambda: sys.stdin.readline().rstrip()
n, m = map(int, input().split())
d = {}
for i in range(n):
    k, v = input().split()
    d.setdefault(k, v)
for i in range(m):
    print(d[input()])