import math
c,a,b=map(int,input().split())
x=math.sqrt(c*c/(a*a+b*b))
print(math.floor(a*x), math.floor(b*x))