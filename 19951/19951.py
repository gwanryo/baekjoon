import sys
input = lambda: sys.stdin.readline().rstrip()

n, m = map(int, input().split())
gnd = list(map(int, input().split()))
idx = [0 for _ in range(n + 1)]

for i in range(m):
    a, b, k = map(int, input().split())
    idx[a - 1] += k
    idx[b] -= k

h = 0
for i in range(n):
    h += idx[i]
    print(gnd[i] + h, end=" ")
