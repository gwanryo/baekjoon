q=[]
for _ in[0]*int(input()):
 m=int(input())
 if m:q+=[m]
 else:q.pop()
print(sum(q))