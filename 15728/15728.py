n,k=map(int,input().split())
a,b=list(map(int,input().split())),list(map(int,input().split()))
f=set(b)
for _ in range(k):
    c = sorted([(-share * team, team) for share in a for team in b])
    b.remove(c[0][1])
c = sorted([-share * team for share in a for team in b])
print(-c[0])