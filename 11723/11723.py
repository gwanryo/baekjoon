import sys
input = lambda: sys.stdin.readline().rstrip()
n = int(input())
m = 0b00000000000000000000
for _ in range(n):
    a = input().split()
    if a[0] == "add":
        m |= (1 << (int(a[1]) - 1))
    elif a[0] == "remove":
        m &= ~(1 << (int(a[1]) - 1))
    elif a[0] == "check":
        print((m >> (int(a[1]) - 1)) & 1)
    elif a[0] == "toggle":
        m ^= 1 << (int(a[1]) - 1)
    elif a[0] == "all":
        m = 0b11111111111111111111
    elif a[0] == "empty":
        m = 0b00000000000000000000