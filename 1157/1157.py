s = input().lower()
a = [0 for x in range(26)]
for i in s:
    a[ord(i) - ord('a')] += 1
m = max(a)
t = a.index(m)
a.remove(m)
n = max(a)
if m == n:
    print('?')
else:
    print(chr(t + 65))
