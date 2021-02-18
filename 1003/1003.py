n = int(input())
for _ in range(n):
    i = int(input())
    if i == 0:
        print(f"1 0")
    else:
        a, b = 0, 1
        for _ in range(i - 1):
            a, b = b, a + b
        print(f"{a} {b}")
