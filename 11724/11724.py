n, m = map(int, input().split())
a = []
for i in range(m):
    x, y = map(int, input().split())
    existX, existY = False, False
    for j, m in enumerate(a):
        if x in m:
            existX = j + 1
        if y in m:
            existY = j + 1
    if existX and existY:
        a[existX - 1].update(a[existY - 1])
        if existX != existY:
            del a[existY - 1]
    elif existX and not existY:
        a[existX - 1].add(y)
    elif not existX and existY:
        a[existY - 1].add(x)
    else:
        a.append(set([x, y]))
for i in range(n):
    existX = 0
    for m in a:
        if i + 1 in m:
            existX = 1
    if not existX:
        a.append(set([i]))
print(len(a))