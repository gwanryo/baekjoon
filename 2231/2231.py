s=input()
l,n=len(s),int(s)
for i in range(n - 9 * l, n):
    s, j = i, i
    while j > 0:
        s += j % 10
        j //= 10
    if n == s:
        print(i)
        break
else:
    print(0)