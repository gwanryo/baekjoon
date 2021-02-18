q=[]
for _ in [0]*int(input()):
 m=int(input())
 q+=[m] if m else q.pop()
print(sum(q))