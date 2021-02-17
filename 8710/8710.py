a,b,c=map(int,input().split())
print((b-a)//c+(0 if (b-a)%c == 0 else 1))