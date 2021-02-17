import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    q = []
    for x in input().split():
        q.append((int(x), True if m == 0 else False))
        m -= 1
    c = 1
    while len(q):
        if max(q)[0] != q[0][0]:
            q.append(q[0])
        else:
            if q[0][1]:
                print(c)
                break
            c += 1
        del q[0]