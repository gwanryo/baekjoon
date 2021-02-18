q=[]
for _ in[0]*int(input()):q+=[[*map(int,input().split()[::-1])]]
for i in sorted(q):print(*i[::-1])