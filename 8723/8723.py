a,b,c=sorted(list(map(int,input().split())))
print(2 if a==b==c else 1 if c**2==b**2+a**2 else 0)