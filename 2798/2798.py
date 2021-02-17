from itertools import combinations
n,m=map(int,input().split())
a=[int(x) for x in input().split()]
k=0
for s in combinations(a, 3):
    if m >= sum(s) and m - sum(s) < m - k:
        k = sum(s)
print(k)