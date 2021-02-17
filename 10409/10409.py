k,a=map(int,input().split())
for i,n in enumerate(input().split()):
 a-=int(n)
 if a<0:
  print(i)
  exit()
print(k)