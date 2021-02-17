n, i, s = int(input()), 1, 0
while s + i < n:
    s += i
    i += 1
a, b = i - n + s + 1, n - s
print(f"{a}/{b}" if i % 2 else f"{b}/{a}")
