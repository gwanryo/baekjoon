x,y=map(int,input().split())
def a(x):
    if x <= 5:
        return 400
    elif x <= 10:
        return 700
    elif x <= 20:
        return 1200
    elif x <= 30:
        return 1700
    else:
        return (x * 57)
def b(x):
    if x <= 2:
        return (x * 90) + 90
    elif x <= 5:
        return (x * 85) + 100
    elif x <= 20:
        return (x * 80) + 125
    elif x <= 40:
        return (x * 70) + 325
    else:
        return (x * 55) + 925
tx = min(a(x // 1000), b(x // 1000))
ty = min(a(y // 1000), b(y // 1000))
t = (tx + ty) / 100
print(f"{t:.2f}")