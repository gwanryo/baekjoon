a,b,c=map(int,input().split())
if a==b==c:
    print(10000+a*1000)
elif a==b or b==c or c==a:
    print(1000+(b if a==b or b==c else c)*100)
else:
    print(max(a,b,c)*100)