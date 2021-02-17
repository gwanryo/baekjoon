a=len
t='\''
for s in input().split():
 l=a(s)
 h,f=l-a(s.lstrip(t)),l-a(s.rstrip(t))
 s=s.replace(t,'')
 print(s[h:a(s)-f],end='')