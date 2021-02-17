import sys
input = lambda: sys.stdin.readline().rstrip()
n, k = map(int, input().split())
a = [i+1 for i in range(n)]
i, c = 0, 0
s = []
while len(a):
    i += 1
    c += 1

    if i > len(a):
        i -= len(a)

    if c == k:
        c = 0
        i -= 1
        s.append(str(a[i]))
        a.remove(a[i])
print(f"<{', '.join(s)}>")