a=1
while a:
 a,b,c=sorted(map(int,input().split()))
 if a>0:print(["wrong","right"][a*a+b*b==c*c])