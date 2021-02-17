e,f,c=(int(x) for x in input().split(" "))
g,t=e+f,0
while g >= c:
    t += g // c
    g = g // c + g % c
print(t)