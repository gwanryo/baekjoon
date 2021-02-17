m,n=map(int,input().split())
for k in range(m,n+1):
    if k <= 1:
        continue
    for i in range(2,int(k**0.5)+1):
        if k!=i and k%i==0:
            break
    else:
        print(k)