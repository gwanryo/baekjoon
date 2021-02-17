a = [[x for x in range(15)]] + [[] for _ in range(14)]
for i in range(1, 15):
    for j in range(15):
        a[i].append(sum(a[i - 1][:(j + 1)]))
T = int(input())
for _ in range(T):
    k, n = int(input()), int(input())
    print(a[k][n])
