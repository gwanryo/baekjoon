import sys
input = lambda: sys.stdin.readline().rstrip()
m, n, b = map(int, input().split())
c, ci = 999999999999999, 0
field = [[int(x) for x in input().split()] for _ in range(m)]

for i in range(257):
    require, remain = 0, 0
    for a in field:
        for m in a:
            if m > i:
                remain += m - i
            else:
                require += i - m

    if require > remain + b:
        continue

    if c >= remain * 2 + require:
        c = remain * 2 + require
        ci = i

print(f"{c} {ci}")