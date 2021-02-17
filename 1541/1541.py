a=[sum(int(s.lstrip('0')) for s in c.split('+')) for c in input().split('-')]
print(a[0]-sum(a[1:]))