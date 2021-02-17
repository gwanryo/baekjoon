n = int(input())
for i in range(n):
    m, s = input().split()
    m = int(m)
    for t in s:
        print(t * m, end='')
    print()