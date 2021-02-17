import sys
input = lambda: sys.stdin.readline().rstrip()
k,n=map(int,input().split());l=[int(input()) for _ in range(k)]
s,e=1,max(l)
a=0
while s<=e:
    m=(s+e)//2
    q=sum([x//m for x in l])
    if q>=n:
        s=m+1
        a=m
    elif q<n:
        e=m-1
print(a)