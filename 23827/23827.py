import sys
input = lambda: sys.stdin.readline().rstrip()
_, s, a = input(), 0, 0
for c in input().split():
    i = int(c)
    a += i * s
    s += int(c)
print(a%1000000007)
