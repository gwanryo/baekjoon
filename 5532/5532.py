a,b,c,d,e=int(input()),int(input()),int(input()),int(input()),int(input())
print(a-max((b//d)+(1 if b%d else 0), (c//e)+(1 if c%e else 0)))