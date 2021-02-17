n, m = int(input()), int(input())
a = []
for i in range(m):
    x, y = map(int, input().split())
    existX, existY = False, False
    for j, b in enumerate(a):
        if x in b:
            existX = j + 1
        if y in b:
            existY = j + 1
    if existX and existY:
        if existX != existY:
            a[existX - 1].update(a[existY - 1])
            del a[existY - 1]
    elif existX and not existY:
        a[existX - 1].add(y)
    elif not existX and existY:
        a[existY - 1].add(x)
    else:
        a.append(set([x, y]))
for b in a:
    if 1 in b:
        print(len(b) - 1)