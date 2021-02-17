a,b,c=map(int,input().split())
print(min([a,b,c,a*b,a*c,b*c,a*b*c],key=lambda x:(-(x&1),-x)))