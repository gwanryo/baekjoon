import math
n = int(input())
for _ in range(n):
    h, w, m = input().split()
    h, w, m = int(h), int(w), int(m)
    print(f"{m % h if m % h else h}{math.ceil(m / h):02d}")