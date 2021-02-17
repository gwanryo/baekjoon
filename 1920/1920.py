import bisect
n=int(input())
a=sorted([int(x) for x in input().split()])
m=int(input())
for k in input().split():
    i = bisect.bisect_left(a, int(k))
    if i != len(a) and a[i] == int(k):
        print(1)
    else:
        print(0)