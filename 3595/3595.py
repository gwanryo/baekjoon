n,m,s=int(input()),10**18+1,""
for i in range(1, n + 1):
    for j in range(1, int(n / i) + 1):
        for k in range(1, int((n / i) / j) + 1):
            if i * j * k < n:
                continue
            elif i * j * k > n:
                break
            else:
                if i * j * 2 + j * k * 2 + k * i * 2 < m:
                    m = i * j * 2 + j * k * 2 + k * i * 2
                    s = f"{i} {j} {k}"
                break
print(s)
