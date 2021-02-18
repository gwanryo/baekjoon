import sys
input = lambda: sys.stdin.readline().rstrip()
n,m=map(int,input().split());a=[]
d = frozenset([input() for _ in range(n)])
s = frozenset([input() for _ in range(m)])
s = sorted(list(d.intersection(s)))
print(len(s))
for m in s:
    print(m)