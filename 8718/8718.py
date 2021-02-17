x,k=map(int,input().split())
if k * 7000 <= x * 1000:
    print(k * 7000)
elif k * 3500 <= x * 1000:
    print(k * 3500)
elif k * 1750 <= x * 1000:
    print(k * 1750)
else:
    print(0)