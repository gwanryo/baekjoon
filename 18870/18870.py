import sys
input = lambda: sys.stdin.readline().rstrip()
_, c, d, x = input(), 0, {}, [int(m) for m in input().split()]
for i, m in enumerate(sorted(x)):
    if d.setdefault(m, i - c) != i - c:
        c += 1
for m in x:
    print(d[m], end=" ")