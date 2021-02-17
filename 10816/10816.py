n, n, c = input(), input(), {}
for t in n.split():
    c.setdefault(t, 0)
    c[t] += 1

m, m = input(), input()
for t in m.split():
    c.setdefault(t, 0)
    print(c[t], end=' ')