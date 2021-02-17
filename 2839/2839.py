n = int(input())
m = n // 5
while m >= 0:
    if (n - m * 5) % 3 == 0:
        print(m + (n - m * 5) // 3)
        break
    else:
        m -= 1
if m < 0:
    print(-1)