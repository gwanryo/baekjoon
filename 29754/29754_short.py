f=lambda x:int(x[:2])*60+int(x[3:])
n,m=map(int,input().split())
s,t,p={},{},m//7
for _ in[0]*n:
 e,y,a,d=input().split()
 s.setdefault(e,[[]for _ in[0]*p])
 s[e][(int(y)-1)//7].append(f(d)-f(a))
for e,w in s.items():t[e]=sum(1 for i in w if len(i)>4 and sum(i)>3599)
h=[e for e,c in t.items()if c==p]
print(*sorted(h)if h else[-1],sep="\n")