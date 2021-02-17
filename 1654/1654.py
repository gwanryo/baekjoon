def c(l,p):
    return sum([x//p for x in l])
def b(a,t):
    s,e=0,max(a) - 1
    while s<=e:
        m=(s+e)//2
        q=c(a,m)
        if q>t:
            s=m+1
        elif q<t:
            e=m-1
        elif q==t:
            s=m+1
    return e if c(l,e)==t else s
k,n=map(int,input().split());l=[int(input()) for _ in range(k)]
print(b(l,n))