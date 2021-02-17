a,b,c=sorted(map(int,input().split()))
if a+b==c:
    print("S")
elif a==b or b==c or c==a:
    print("S")
else:
    print("N")