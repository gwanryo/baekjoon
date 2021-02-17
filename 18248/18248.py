n,m=map(int,input().split())
b=[list(map(int,input().split())) for _ in range(n)]
c=[x[1] for x in sorted([(-sum(x), x) for x in b])]
for a in zip(*c):
    a = [-x for x in a]
    if f"{list(a)}" != f"{sorted(a)}":
        print("NO")
        break
else:
    print("YES")
