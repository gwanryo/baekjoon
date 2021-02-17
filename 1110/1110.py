n = int(input())
a, b = n // 10, n % 10
count = 0
while True:
    count += 1
    a, b = b, (a + b) % 10
    if (a * 10 + b == n):
        print(count)
        break