from itertools import combinations as q
l,c=map(int,input().split())
a=sorted(input().split())
for r in q(a,l):
 v=len([x for x in r if x in['a', 'e', 'i', 'o', 'u']])
 s=len(r)-v
 if v>0 and s>1:
  print(''.join(r))