a = {}
for i in range(10):
    for j in range(10):
        for k in range(10):
            for l in range(10):
                a.setdefault(1001 * i + 101 * j + 11 * k + 2 * l, 0)

for i in range(10000):
    if i not in a:
        print(i)
