n, c, t, p = int(input()), [0 for _ in range(10)], 1, 0
while n:
    m, n = n % 10, n // 10

    # 0 ~ 3 * 3
    for i in range(m):
        c[i] += (n + 1) * t

    # 4
    c[m] += n * t + p + 1

    # 5 ~ 9 * 2
    for i in range(m + 1, 10):
        c[i] += n * t
    # 0
    c[0] -= t

    p += m * t
    t *= 10

print(" ".join(map(str,c)))